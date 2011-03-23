#include "../Vector2.h"
#include "../Entity.h"

namespace Monocle
{
	class FringeTile;
	class Scene;
	class Entity;


	enum FringeTileEditorState
	{
		FTES_NONE=0,
		FTES_MOVE,
		FTES_ROTATE,
		FTES_SCALE,
		FTES_MAX
	};

	/*
	class Cursor : public Entity
	{
	public:
		Cursor();
		void Update();
		void Render();
	};
	*/

	class FringeTileEditor
	{
	public:
		FringeTileEditor();
		void Init(Scene *scene);
		void Enable();
		void Disable();
		void Update();

	protected:
		void UpdateCamera();
		void UpdateSelect();
		void UpdateOpportunity();
		void UpdateMove();
		void UpdateRotate();
		void UpdateScale();

		void Clone();

		void SetState(FringeTileEditorState state);

		void Select(Entity *entity);

		Entity *selectedEntity;
		FringeTile *selectedFringeTile;
		Scene *scene;
		bool isOn;

		Vector2 moveOffset;
		Vector2 moveStartPosition;
		float startRotation;

		bool waitForLMBRelease;

		FringeTileEditorState state;

		//Cursor *cursor;
	};
}