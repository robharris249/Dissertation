#include "../../Common/Window.h"
#include "../../Common/TextureLoader.h"
#include "../../Common/Vector3.h"
#include "../../Common/Vector4.h"
#include "../../Common/MeshGeometry.h"
#include "../../Common/Maths.h"

#include "../../Plugins/OpenGLRendering/OGLRenderer.h"
#include "../../Plugins/OpenGLRendering/OGLMesh.h"
//#include "../../Plugins/OpenGLRendering/OGLShader.h"
#include "../../Plugins/OpenGLRendering/OGLTexture.h"

#include "Renderer.h"
#include "RasterisationMesh.h"
#include <vector>
#include "DiamondSquare.h"
#include "Node2D.h"
#include <iostream>
#include <map>

using namespace NCL;
using namespace CSC3223;
using namespace std;

void diamondSquareGrid(Renderer& renderer, DiamondSquare* d) {
	OGLMesh* testpoints = new OGLMesh();
	OGLMesh* points = new OGLMesh();
	vector<Vector3> generatedPoints = {};
	
	for (int i = 0; i <= d->size; i += d->step / 2) {
		for (int j = 0; j <= d->size; j += d->step / 2) {
			generatedPoints.push_back(Vector3(d->grid[i][j]->x / 10.0f, d->grid[i][j]->y / 10.0f, d->grid[i][j]->z / 10.0f));
		}
	}

	int jump = sqrt(generatedPoints.size());

	for (int i = 0; i < sqrt(generatedPoints.size()) - 1; i++) { // Rows
		for (int j = 0; j < sqrt(generatedPoints.size()) - 1; j++) {

			int x = j;
			int y = i * jump;

			int pointA = x + y;
			int pointB = x + y + 1;
			int pointC = x + y + jump;
			int pointD = x + y + jump + 1;

			//first Triangle
			OGLMesh* firstTriangle = new OGLMesh();
			firstTriangle->SetVertexPositions({ generatedPoints.at(pointA), generatedPoints.at(pointC), generatedPoints.at(pointD) });

			vector<Vector4> firstTriColours = {};
			if (generatedPoints.at(pointA).z >= 0) {
				firstTriColours.push_back(Vector4(generatedPoints.at(pointA).z / 10.0f, 0.0f, 0.0f, 1.0f));
			}
			else {
				firstTriColours.push_back(Vector4(0.0f, 0.0f, -(generatedPoints.at(pointA).z / 10.0f), 1.0f));
			}

			if (generatedPoints.at(pointC).z >= 0) {
				firstTriColours.push_back(Vector4(generatedPoints.at(pointC).z / 10.0f, 0.0f, 0.0f, 1.0f));
			}
			else {
				firstTriColours.push_back(Vector4(0.0f, 0.0f, -(generatedPoints.at(pointB).z / 10.0f), 1.0f));
			}

			if (generatedPoints.at(pointD).z >= 0) {
				firstTriColours.push_back(Vector4(generatedPoints.at(pointD).z / 10.0f, 0.0f, 0.0f, 1.0f));
			}
			else {
				firstTriColours.push_back(Vector4(0.0f, 0.0f, -(generatedPoints.at(pointD).z / 10.0f), 1.0f));
			}

			firstTriangle->SetVertexColours(firstTriColours);
			firstTriangle->SetPrimitiveType(GeometryPrimitive::Triangles);
			firstTriangle->UploadToGPU();
			renderer.AddRenderObject(new RenderObject(firstTriangle));

			//Second Triangle
			OGLMesh* secondTriangle = new OGLMesh();
			secondTriangle->SetVertexPositions({ generatedPoints.at(pointA), generatedPoints.at(pointB), generatedPoints.at(pointD) });

			vector<Vector4> secondTriColours = {};

			if (generatedPoints.at(pointA).z >= 0) {
				secondTriColours.push_back(Vector4(generatedPoints.at(pointA).z / 10.0f, 0.0f, 0.0f, 1.0f));
			}
			else {
				secondTriColours.push_back(Vector4(0.0f, 0.0f, -(generatedPoints.at(pointA).z / 10.0f), 1.0f));
			}

			if (generatedPoints.at(pointB).z >= 0) {
				secondTriColours.push_back(Vector4(generatedPoints.at(pointB).z / 10.0f, 0.0f, 0.0f, 1.0f));
			}
			else {
				secondTriColours.push_back(Vector4(0.0f, 0.0f, -(generatedPoints.at(pointB).z / 10.0f), 1.0f));
			}

			if (generatedPoints.at(pointD).z >= 0) {
				secondTriColours.push_back(Vector4(generatedPoints.at(pointD).z / 10.0f, 0.0f, 0.0f, 1.0f));
			}
			else {
				secondTriColours.push_back(Vector4(0.0f, 0.0f, -(generatedPoints.at(pointD).z / 10.0f), 1.0f));
			}

			secondTriangle->SetVertexColours(secondTriColours);
			secondTriangle->SetPrimitiveType(GeometryPrimitive::Triangles);
			secondTriangle->UploadToGPU();
			renderer.AddRenderObject(new RenderObject(secondTriangle));
		}
	}
}

int main() {

	Window* w = Window::CreateGameWindow("Dissertation");

	//w->SetFullScreen(true);

	if (!w->HasInitialised()) {
		return -1;
	}

	auto t1 = std::chrono::high_resolution_clock::now();//Time before algorithm is run

	//  size =     2 ^10
	int size = pow(2, 10);
	DiamondSquare* d = new DiamondSquare(size, 1024);
	int runs = 8;
	for (int i = 0; i < runs; i++) {
		d->run();
	}
	
	auto t2 = std::chrono::high_resolution_clock::now();//Time after algorithm is run

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();//Time taken to run diamond-square

	cout << "algorithm Duration " << duration << endl;//print the time taken to perform the algorithm

	Renderer* renderer = new Renderer(*w);
	glClearColor(0.8f, 0.8f, 0.8f, 0.0f);

	auto t3 = std::chrono::high_resolution_clock::now();//Time before rendering is run
	diamondSquareGrid(*renderer, d);
	auto t4 = std::chrono::high_resolution_clock::now();//Time after rendering is run
	auto Rduration = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();//Time taken to run diamond-square
	cout << "rendering Duration " << Rduration << endl;//print the time taken to perform the rendering

	float aspect = w->GetScreenAspect();
	Matrix4 proj = Matrix4::Perspective(0.5f, 1000, aspect, 45.0);//set near and far planes as first two (view distances), then field of veiw
	renderer->SetProjectionMatrix(proj);

	Vector3 viewPosition(-50, -50, -150);
	
	float pitchRotation = 0.0f;
	float yawRotation = 0.0f;
	float rollRotation = 0.0f;

#define CAMSPEED 150.f
	while (w->UpdateWindow() && !Window::GetKeyboard()->KeyDown(KEYBOARD_ESCAPE)) {
		float time = w->GetTimer()->GetTimeDelta();
		const float camSpeed = CAMSPEED * time;

		renderer->Update(time);

		//renderer->DrawString("OpenGL Rendering!", Vector2(10, 10));

		renderer->Render();

		if (Window::GetKeyboard()->KeyPressed(KEYBOARD_PRIOR)) {
			w->ShowConsole(true);
		}
		if (Window::GetKeyboard()->KeyPressed(KEYBOARD_NEXT)) {
			w->ShowConsole(false);
		}

		if (Window::GetKeyboard()->KeyPressed(KEYBOARD_HOME)) {
			w->SetFullScreen(true);
		}
		if (Window::GetKeyboard()->KeyPressed(KEYBOARD_END)) {
			w->SetFullScreen(false);
		}

		//Movement stuff
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_A)) {
			viewPosition.x += camSpeed / 10;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_D)) {
			viewPosition.x -= camSpeed / 10;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_W)) {
			viewPosition.y -= camSpeed / 10;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_S)) {
			viewPosition.y += camSpeed / 10;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_SHIFT)) {
			viewPosition.z -= camSpeed / 10;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_SPACE)) {
			viewPosition.z += camSpeed / 10;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_Q)) { // roll up
			pitchRotation += camSpeed / 10;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_E)) { // roll down
			pitchRotation -= camSpeed / 10;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_Z)) { // turn 
			yawRotation += camSpeed / 10;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_C)) { // roll 
			yawRotation -= camSpeed / 10;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_1)) { // turn 
			rollRotation += camSpeed / 10;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_3)) { // roll 
			rollRotation -= camSpeed / 10;
		}

		renderer->SetViewMatrix(Matrix4::Translation(viewPosition)
								* Matrix4::Rotation(pitchRotation, Vector3(1,0,0))
								* Matrix4::Rotation(yawRotation, Vector3(0, 1, 0))
								* Matrix4::Rotation(rollRotation, Vector3(0, 0, 1)));

		//w->SetTitle(std::to_string(time));
	}

	delete renderer;

	Window::DestroyGameWindow();
};