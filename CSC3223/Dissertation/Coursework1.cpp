#include "../../Common/Window.h"
#include "../../Common/TextureLoader.h"
#include "../../Common/Vector3.h"
#include "../../Common/Vector4.h"
#include "../../Common/MeshGeometry.h"
#include "../../Common/Maths.h"

#include "../../Plugins/OpenGLRendering/OGLRenderer.h"
#include "../../Plugins/OpenGLRendering/OGLMesh.h"
#include "../../Plugins/OpenGLRendering/OGLShader.h"
#include "../../Plugins/OpenGLRendering/OGLTexture.h"

#include "Renderer.h"
#include "RasterisationMesh.h"

using namespace NCL;
using namespace CSC3223;
using namespace std;

void StarMap(Renderer& renderer) {
	
	for (int i = 0; i < 8000; i++) {
		int max = 500;
		int min = -500;
		float x = rand() % (max - min + 1) + min;
		float y = rand() % (max - min + 1) + min;
		float z = rand() % (max - min + 1) + min;

		OGLMesh* star = new OGLMesh();
		star->SetVertexPositions({ Vector3(x , y, -z) });

		star->SetVertexColours({ Vector4(1,1,1,1) });
		star->SetPrimitiveType(GeometryPrimitive::Points);
		star->UploadToGPU();

		renderer.AddRenderObject(new RenderObject(star));
	}
}

void Xwing(Renderer& renderer) {

	//Vector3* origin = new Vector3(270, 160, -100);

	//----------------------- Ship Nose -------------------------------

	OGLMesh* shipNose1 = new OGLMesh();//top
	shipNose1->SetVertexPositions({ Vector3(250, 250, -115), Vector3(230,160,-100), Vector3(270,160,-100) });
	shipNose1->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipNose1->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipNose1->UploadToGPU();

	OGLMesh* shipNose2 = new OGLMesh();//right
	shipNose2->SetVertexPositions({ Vector3(250, 250, -115), Vector3(270,160,-100), Vector3(270,160,-130) });
	shipNose2->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipNose2->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipNose2->UploadToGPU();

	OGLMesh* shipNose3 = new OGLMesh();//left
	shipNose3->SetVertexPositions({ Vector3(250, 250, -115), Vector3(230,160,-100), Vector3(230,160,-130) });
	shipNose3->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipNose3->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipNose3->UploadToGPU();

	OGLMesh* shipNose4 = new OGLMesh();//bottom
	shipNose4->SetVertexPositions({ Vector3(250, 250, -115), Vector3(230,160,-130), Vector3(270,160,-130) });
	shipNose4->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipNose4->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipNose4->UploadToGPU();

	//----------------------- ship body -------------------------------

	OGLMesh* shipBody1 = new OGLMesh();//top
	shipBody1->SetVertexPositions({ Vector3(230, 160, -100), Vector3(270,160,-100), Vector3(230,110,-100) });
	shipBody1->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipBody1->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipBody1->UploadToGPU();

	OGLMesh* shipBody2 = new OGLMesh();//top
	shipBody2->SetVertexPositions({ Vector3(270, 110, -100), Vector3(270,160,-100), Vector3(230,110,-100) });
	shipBody2->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipBody2->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipBody2->UploadToGPU();

	OGLMesh* shipBody3 = new OGLMesh();//right
	shipBody3->SetVertexPositions({ Vector3(270, 160, -100), Vector3(270,110,-100), Vector3(270,110,-130) });
	shipBody3->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipBody3->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipBody3->UploadToGPU();

	OGLMesh* shipBody4 = new OGLMesh();//right
	shipBody4->SetVertexPositions({ Vector3(270, 160, -100), Vector3(270,160,-130), Vector3(270,110,-130) });
	shipBody4->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipBody4->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipBody4->UploadToGPU();

	OGLMesh* shipBody5 = new OGLMesh();//left
	shipBody5->SetVertexPositions({ Vector3(230, 160, -100), Vector3(230,110,-100), Vector3(230,110,-130) });
	shipBody5->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipBody5->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipBody5->UploadToGPU();

	OGLMesh* shipBody6 = new OGLMesh();//left
	shipBody6->SetVertexPositions({ Vector3(230, 160, -100), Vector3(230,160,-130), Vector3(230,110,-130) });
	shipBody6->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipBody6->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipBody6->UploadToGPU();

	OGLMesh* shipBody7 = new OGLMesh();//bottom
	shipBody7->SetVertexPositions({ Vector3(230, 160, -130), Vector3(270,160,-130), Vector3(230,110,-130) });
	shipBody7->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipBody7->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipBody7->UploadToGPU();

	OGLMesh* shipBody8 = new OGLMesh();//bottom
	shipBody8->SetVertexPositions({ Vector3(270, 160, -130), Vector3(270,110,-130), Vector3(230,110,-130) });
	shipBody8->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipBody8->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipBody8->UploadToGPU();

	OGLMesh* shipBody9 = new OGLMesh();//rear
	shipBody9->SetVertexPositions({ Vector3(230, 110, -100), Vector3(270,110,-100), Vector3(230,110,-130) });
	shipBody9->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipBody9->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipBody9->UploadToGPU();

	OGLMesh* shipBody10 = new OGLMesh();//rear
	shipBody10->SetVertexPositions({ Vector3(270, 110, -100), Vector3(230,110,-130), Vector3(270,110,-130) });
	shipBody10->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipBody10->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipBody10->UploadToGPU();

	//----------------------- Ship wing -------------------------------

	OGLMesh* shipWing1 = new OGLMesh();//top right
	shipWing1->SetVertexPositions({ Vector3(230, 140, -100), Vector3(230,110,-100), Vector3(180,110,-80) });
	shipWing1->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipWing1->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipWing1->UploadToGPU();

	OGLMesh* shipWing2 = new OGLMesh();//top left
	shipWing2->SetVertexPositions({ Vector3(270, 140, -100), Vector3(270,110,-100), Vector3(320,110,-80) });
	shipWing2->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipWing2->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipWing2->UploadToGPU();

	OGLMesh* shipWing3 = new OGLMesh();//bottom right
	shipWing3->SetVertexPositions({ Vector3(230, 140, -130), Vector3(230,110,-130), Vector3(180,110,-150) });
	shipWing3->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipWing3->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipWing3->UploadToGPU();

	OGLMesh* shipWing4 = new OGLMesh();//bottom left
	shipWing4->SetVertexPositions({ Vector3(270, 140, -130), Vector3(270,110,-130), Vector3(320,110,-150) });
	shipWing4->SetVertexColours({ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1) });
	shipWing4->SetPrimitiveType(GeometryPrimitive::Triangles);
	shipWing4->UploadToGPU();

	Matrix4 scale = Matrix4::Scale(Vector3(0.3, 0.5, 0.25));
	Matrix4 rotate = Matrix4::Rotation(-90.0f, Vector3(1, 0, 0));

	
	renderer.AddRenderObject(new RenderObject(shipNose1, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipNose2, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipNose3, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipNose4, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipBody1, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipBody2, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipBody3, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipBody4, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipBody5, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipBody6, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipBody7, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipBody8, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipBody9, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipBody10, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipWing1, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipWing2, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipWing3, rotate* scale));
	renderer.AddRenderObject(new RenderObject(shipWing4, rotate* scale));
}

void Asteroid(Renderer& renderer, Vector3* origin, Vector3* s, Vector3* t, float r) {

	OGLMesh* shell1 = new OGLMesh();
	shell1->SetVertexPositions({ 
		*origin, *origin + Vector3(0,40,-20),* origin + Vector3(30,30,-20),
		*origin + Vector3(40,0,-20), *origin + Vector3(30,-30,-20), *origin + Vector3(0,-40,-20),
		*origin + Vector3(-30,-30,-20), *origin + Vector3(-40,0,-20), *origin + Vector3(-30,30,-20), *origin + Vector3(0,40,-20) });
	shell1->SetVertexColours({ 
		Vector4(0.1,0.1,0.1,1), Vector4(0,1,0,1), Vector4(0.1,0.1,0.1,1),
		Vector4(0,1,0,1), Vector4(0.1,0.1,0.1,1), Vector4(0,1,0,1),
		Vector4(0.1,0.1,0.1,1), Vector4(0,1,0,1), Vector4(0.1,0.1,0.1,1), Vector4(0,1,0,1) });
	shell1->SetPrimitiveType(GeometryPrimitive::TriangleFan);
	shell1->UploadToGPU();
	

	OGLMesh* shell2 = new OGLMesh();
	shell2->SetVertexPositions({
		*origin + Vector3(0, 0, -40), *origin + Vector3(0,40,-20), *origin + Vector3(30,30,-20),
		*origin + Vector3(40,0,-20), *origin + Vector3(30,-30,-20), *origin + Vector3(0,-40,-20),
		*origin + Vector3(-30,-30,-20), *origin + Vector3(-40,0,-20), *origin + Vector3(-30,30,-20), *origin + Vector3(0,40,-20) });
	shell2->SetVertexColours({
		Vector4(0.1,0.1,0.1,1), Vector4(0,1,0,1), Vector4(0.1,0.1,0.1,1),
		Vector4(0,1,0,1), Vector4(0.1,0.1,0.1,1), Vector4(0,1,0,1),
		Vector4(0.1,0.1,0.1,1), Vector4(0,1,0,1), Vector4(0.1,0.1,0.1,1), Vector4(0,1,0,1) });
	shell2->SetPrimitiveType(GeometryPrimitive::TriangleFan);
	shell2->UploadToGPU();

	Matrix4 rotate = Matrix4::Rotation(r, Vector3(1, 0, 0));
	Matrix4 scale = Matrix4::Scale(*s);
	Matrix4 translate = Matrix4::Translation(*t);

	renderer.AddRenderObject(new RenderObject(shell1, translate * rotate * scale));
	renderer.AddRenderObject(new RenderObject(shell2, translate * rotate * scale));
}

void RedPlanet(Renderer& renderer, Vector3* origin) {
	OGLMesh* shell1 = new OGLMesh();
	shell1->SetVertexPositions({
		*origin, 
		*origin + Vector3(0,40,0),
		*origin + Vector3(15,35,0),
		*origin + Vector3(30,30,0),
		*origin + Vector3(35,15,0),
		*origin + Vector3(40,0,0),
		*origin + Vector3(35,-15,0),
		*origin + Vector3(30,-30,0),
		*origin + Vector3(15,-35,0),
		*origin + Vector3(0,-40,0),
		*origin + Vector3(-15,-35,0),
		*origin + Vector3(-30,-30,0),
		*origin + Vector3(-35,-15,0),
		*origin + Vector3(-40,0,0),
		*origin + Vector3(-35,15,0),
		*origin + Vector3(-30,30,0),
		*origin + Vector3(-15,35,0),
		*origin + Vector3(0,40,0) });

	float ab = 0.3;
	shell1->SetVertexColours({
		Vector4(1,1,1,ab),
		Vector4(1,0,0,ab), Vector4(1,0,0,ab), Vector4(1,0,0,ab), Vector4(1,0,0,ab),
		Vector4(1,0,0,ab), Vector4(1,0,0,ab), Vector4(1,0,0,ab), Vector4(1,0,0,ab),
		Vector4(1,0,0,ab), Vector4(1,0,0,ab), Vector4(1,0,0,ab), Vector4(1,0,0,ab),
		Vector4(1,0,0,ab), Vector4(1,0,0,ab), Vector4(1,0,0,ab), Vector4(1,0,0,ab),
		Vector4(1,0,0,ab) });
	shell1->SetPrimitiveType(GeometryPrimitive::TriangleFan);
	shell1->UploadToGPU();

	//renderer.AddRenderObject(new RenderObject(shell1, translate * rotate * scale));
	renderer.AddRenderObject(new RenderObject(shell1));
}

void BluePlanet(Renderer& renderer, Vector3* origin) {
	OGLMesh* shell1 = new OGLMesh();
	shell1->SetVertexPositions({
		*origin,
		*origin + Vector3(0,40,0),
		*origin + Vector3(15,35,0),
		*origin + Vector3(30,30,0),
		*origin + Vector3(35,15,0),
		*origin + Vector3(40,0,0),
		*origin + Vector3(35,-15,0),
		*origin + Vector3(30,-30,0),
		*origin + Vector3(15,-35,0),
		*origin + Vector3(0,-40,0),
		*origin + Vector3(-15,-35,0),
		*origin + Vector3(-30,-30,0),
		*origin + Vector3(-35,-15,0),
		*origin + Vector3(-40,0,0),
		*origin + Vector3(-35,15,0),
		*origin + Vector3(-30,30,0),
		*origin + Vector3(-15,35,0),
		*origin + Vector3(0,40,0) });
	shell1->SetVertexColours({
		Vector4(1,1,1,1),
		Vector4(0,0,1,1), Vector4(0,0,1,1), Vector4(0,0,1,1), Vector4(0,0,1,1),
		Vector4(0,0,1,1), Vector4(0,0,1,1), Vector4(0,0,1,1), Vector4(0,0,1,1),
		Vector4(0,0,1,1), Vector4(0,0,1,1), Vector4(0,0,1,1), Vector4(0,0,1,1),
		Vector4(0,0,1,1), Vector4(0,0,1,1), Vector4(0,0,1,1), Vector4(0,0,1,1),
		Vector4(0,0,1,1) });
	shell1->SetPrimitiveType(GeometryPrimitive::TriangleFan);
	shell1->UploadToGPU();

	//renderer.AddRenderObject(new RenderObject(shell1, translate * rotate * scale));
	renderer.AddRenderObject(new RenderObject(shell1));
}

void name(Renderer& renderer) {
	Vector3 origin(1000, 1000, -50);

	OGLMesh* letterR = (OGLMesh*)RasterisationMesh::CreateLineFromPoints({ 
	origin + Vector3(-85,35,0), origin + Vector3(-55,35,0), origin + Vector3(-45,25,0),
	origin + Vector3(-45,5,0), origin + Vector3(-55,-5,0), origin + Vector3(-65,5,0),
	origin + Vector3(-45,-35,0), origin + Vector3(-35,-35,0), origin + Vector3(-75,-5,0),
	origin + Vector3(-75,-35,0), origin + Vector3(-85,-35,0), origin + Vector3(-85,35,0) },
	{ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1), Vector4(1,0,0,1),
	Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1), Vector4(1,0,0,1), 
	Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1), Vector4(1,0,0,1) }, false);

	OGLMesh* letterO = (OGLMesh*)RasterisationMesh::CreateLineFromPoints({
	origin + Vector3(-15,35,0), origin + Vector3(15,35,0), origin + Vector3(25,25,0),
	origin + Vector3(25,-25,0), origin + Vector3(15,-35,0), origin + Vector3(-15,-35,0),
	origin + Vector3(-25,-25,0), origin + Vector3(-25,25,0), origin + Vector3(-15,35,0) },
	{ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1), Vector4(1,0,0,1),
	Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1), Vector4(1,0,0,1), Vector4(1,0,0,1) }, false);

	OGLMesh* letterB = (OGLMesh*)RasterisationMesh::CreateLineFromPoints({
	origin + Vector3(45,35,0), origin + Vector3(75,35,0), origin + Vector3(85,25,0),
	origin + Vector3(85,5,0), origin + Vector3(65,0,0), origin + Vector3(85,5,0),
	origin + Vector3(85,-25,0), origin + Vector3(-75,-35,0), origin + Vector3(-45,-35,0), origin + Vector3(45,35,0) },
	{ Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1), Vector4(1,0,0,1),
	Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(0,0,1,1), Vector4(1,0,0,1), Vector4(0,1,0,1), Vector4(1,0,0,1) }, false);


	renderer.AddRenderObject(new RenderObject(letterR));
	renderer.AddRenderObject(new RenderObject(letterO));
	renderer.AddRenderObject(new RenderObject(letterB));
}

int main() {
	Window*w = Window::CreateGameWindow("CSC3223 Coursework 1!");

	//w->SetFullScreen(true);

	if (!w->HasInitialised()) {
		return -1;
	}


	Renderer*	renderer = new Renderer(*w);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	Vector3 namePosition(500, 500, -500);

	StarMap(*renderer);
	Xwing(*renderer);

	//Spawn 50 random Asteroids ---------
	for (int i = 0; i < 50; i++) {
		int max = 500;
		int min = -500;
		float x = rand() % (max - min + 1) + min;
		float y = rand() % (max - min + 1) + min;
		float z = rand() % (max - min + 1) + min;

		Vector3* origin = new Vector3(x, y, z);

		max = 6;
		float scaleFactor = 0;
		scaleFactor = ((rand() % (max + 1)) + 1);
		scaleFactor /= 10;

		Vector3* scale = new Vector3(scaleFactor, scaleFactor, scaleFactor);
		
		Vector3* trans = new Vector3((rand() % 1000) - 500, (rand() % 1000) - 500, -(rand() % 500));
		
		max = 360;
		float rotationAmount = rand() % (max + 1);
		Asteroid(*renderer, origin, scale, trans, rotationAmount);
	}   
	// ----------------------------------

	BluePlanet(*renderer, new Vector3(-45, 0, -30));
	RedPlanet(*renderer, new Vector3(-100, 0, 0));
	name(*renderer);

	float aspect = w->GetScreenAspect();
	Matrix4 proj = Matrix4::Perspective(0.5f, -100, aspect, 45.0);//set near and far planes as first two (view distances), then field of veiw
	renderer->SetProjectionMatrix(proj);

	Vector3 viewPosition(0, 0, 0);

#define CAMSPEED 150.f
	while (w->UpdateWindow() && !Window::GetKeyboard()->KeyDown(KEYBOARD_ESCAPE)) {
		float time = w->GetTimer()->GetDeltaTime();
		const float camSpeed = CAMSPEED * time;

		renderer->Update(time);

		renderer->DrawString("OpenGL Rendering!", Vector2(10, 10));

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
			viewPosition.x += camSpeed;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_D)) {
			viewPosition.x -= camSpeed;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_W)) {
			viewPosition.z += camSpeed;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_S)) {
			viewPosition.z -= camSpeed;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_SHIFT)) {
			viewPosition.y -= camSpeed;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_SPACE)) {
			viewPosition.y += camSpeed;
		}

		//Depth Buffer stuff
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_F1)) { //Toggles
			renderer->enableDepthBuffer(true);
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_F2)) {
			
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_F3)) {
			
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_F4)) {
			
		}

		//Alpha Blending stuff
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_F5)) { //Toggles
			renderer->EnableBlending(true);
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_F6)) {
			renderer->SetBlendToLinear();
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_F7)) {
			renderer->SetBlendToAdditive();
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_F8)) {
			renderer->SetBlendToInvert();
		}

		renderer->SetViewMatrix(Matrix4::Translation(viewPosition));

		//Display name stuff
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_F9)) {
			renderer->SetViewMatrix(Matrix4::Translation(namePosition));
		}

		w->SetTitle(std::to_string(time));
	}

	delete renderer;

	Window::DestroyGameWindow();
}