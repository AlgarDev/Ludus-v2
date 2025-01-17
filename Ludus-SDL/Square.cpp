#include "Square.h"

Square::Square(float x, float y, float scale, b2World* World, Texture* texture) {
	bdef.type = b2_dynamicBody;
	this->scale = scale;
	bdef.position.Set(x, y);
	bdef.bullet = true;
	fdef.isSensor = true;
	Body = World->CreateBody(&bdef);
	this->World = World;
	pshape = new b2PolygonShape();
	this->width = texture->spriteWidth;
	this->height = texture->spriteHeight;
	pshape->SetAsBox(width*scale, height*scale);
	this->texture = texture;
	fdef.shape = pshape;
	fdef.density = 1;
	fdef.restitution = 0.0f;
	fdef.friction = 1;
	Body->CreateFixture(&fdef);
	Body->GetUserData().pointer = (uintptr_t)this;
}

void Square::removeCollisions(){
	Body->DestroyFixture(Body->GetFixtureList());
}

Square::~Square() {
    // Check if the Box2D shape was dynamically allocated
    if (pshape) {
        delete pshape;
        pshape = nullptr; // Avoid dangling pointers
    }

    // Remove the body from the Box2D world if it exists
    if (Body && World) {
        World->DestroyBody(Body);
        Body = nullptr; // Avoid dangling pointers
    }

    // The Texture pointer is not deleted here, assuming it is managed elsewhere
    // If ownership of `texture` belongs to this class, you may add:
    // delete texture;
    // texture = nullptr;
}

float Square::getX(){
	return Body->GetPosition().x;
}
float Square::getY(){
	return Body->GetPosition().y;
}

void Square::render() {
	float x = Body->GetPosition().x;
	float y = Body->GetPosition().y;
    float angle = Body->GetAngle();
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(angle * 180.0f / 3.14159f, 0.0f, 0.0f, 1.0f);
	glScalef(scale, scale, 0.f);

	float x1 = (texture->spriteColumn * texture->spriteWidth) / (float)texture->image->w;  // Left coordinate (normalized)
    float y1 = (texture->spriteRow * texture->spriteHeight) / (float)texture->image->h;  // Bottom coordinate (normalized)
    float x2 = ((texture->spriteColumn + 1) * texture->spriteWidth) / (float)texture->image->w;  // Right coordinate (normalized)
    float y2 = ((texture->spriteRow + 1) * texture->spriteHeight) / (float)texture->image->h;  // Top coordinate (normalized)
    texture->Apply();

	glBegin(GL_QUADS);
	glTexCoord2f(x1, y1);
    glVertex2f( (-width / 2.f) , (-height / 2.f) );
	glTexCoord2f(x2, y1);
    glVertex2f( (width / 2.f) , (-height / 2.f) );
    glTexCoord2f(x2, y2);
    glVertex2f( (width / 2.f) , (height / 2.f) );
    glTexCoord2f(x1, y2);
    glVertex2f( (-width / 2.f) , (height / 2.f) );
    glEnd();

    glPopMatrix(); // Restore the original matrix state
}