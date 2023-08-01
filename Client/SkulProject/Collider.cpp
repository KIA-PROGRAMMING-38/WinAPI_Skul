#include "global_include.h"
#include "Collider.h"

#include "HandleStore.h"

#include "GameObject.h"
#include "Transform.h"

Collider::Collider()
	: _transform(nullptr)
	, _offsetPos(0.f, 0.f)
	, _finalPos(0.f, 0.f)
	, _scale(0.f, 0.f)
{
}

Collider::Collider(const Collider& other)
	: _transform(nullptr)
	, _offsetPos(other._offsetPos)
	, _finalPos(other._finalPos)
	, _scale(other._scale)
{
}

Collider::~Collider()
{
}

void Collider::Initialize()
{
	_transform = GetGameObject()->GetComponent<Transform>();
}

void Collider::Update()
{
	// Object의 위치를 따라간다.
	Vector2 objectPos = _transform->GetPosition();
	_finalPos = objectPos + _offsetPos;
}

void Collider::Render(HDC hDC)
{
	HPEN pen = HandleStore::GetPen(PenType::Green);
	HPEN defaultPen = (HPEN)SelectObject(hDC, pen);
	
	HBRUSH brush = HandleStore::GetBrush(BrushType::Hollow);
	HBRUSH defaultBrush = (HBRUSH)SelectObject(hDC, brush);
	
	//Vector2 position = Camera::GetInst()->GetRenderPos(_finalPos);
	Vector2 position = _finalPos;
	Vector2 scale = Vector2(_scale.x * _transform->GetScale().x, _scale.y * _transform->GetScale().y);
	
	//Rectangle(hDC, (int)(position.x - _scale.x / 2.f), (int)(position.y - _scale.y / 2.f), (int)(position.x + _scale.x / 2.f), (int)(position.y + _scale.y / 2.f));
	Rectangle(hDC, (int)(position.x), (int)(position.y), (int)(position.x + _scale.x), (int)(position.y + _scale.y));
	
	SelectObject(hDC, defaultPen);
	SelectObject(hDC, defaultBrush);
}

void Collider::OnCollisionEnter(Collider* otherCollider)
{
	GetGameObject()->OnCollisionEnter(otherCollider);
}

void Collider::OnCollisionStay(Collider* otherCollider)
{
	GetGameObject()->OnCollisionStay(otherCollider);
}

void Collider::OnCollisionExit(Collider* otherCollider)
{
	GetGameObject()->OnCollisionExit(otherCollider);
}