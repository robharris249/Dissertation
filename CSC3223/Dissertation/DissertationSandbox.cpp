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


int main() {
	Window* w = Window::CreateGameWindow("Dissertation");

	//w->SetFullScreen(true);

	if (!w->HasInitialised()) {
		return -1;
	}



	Renderer* renderer = new Renderer(*w);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);



	float aspect = w->GetScreenAspect();
	Matrix4 proj = Matrix4::Perspective(0.5f, -100, aspect, 45.0);//set near and far planes as first two (view distances), then field of veiw
	renderer->SetProjectionMatrix(proj);

	Vector3 viewPosition(0, 0, 0);

#define CAMSPEED 150.f
	while (w->UpdateWindow() && !Window::GetKeyboard()->KeyDown(KEYBOARD_ESCAPE)) {
		float time = w->GetTimer()->GetTimeDelta();
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

		w->SetTitle(std::to_string(time));
	}

	delete renderer;

	Window::DestroyGameWindow();
}