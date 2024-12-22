#include "Square.h"

Square::Square(float x, float y, float width, float height, b2World* World, Texture* texture) {
	bdef.type = b2_dynamicBody;
	bdef.position.Set(x, y);
	bdef.bullet = true;
	fdef.isSensor = true;
	Body = World->CreateBody(&bdef);
	pshape = new b2PolygonShape();
	pshape->SetAsBox(width, height);
	this->texture = texture;
	fdef.shape = pshape;
	fdef.density = 1;
	fdef.restitution = 0.0f;
	fdef.friction = 1;
	Body->CreateFixture(&fdef);
	this->width = width;
	this->height = height;
}

void Square::render() {
	float x = Body->GetPosition().x;
	float y = Body->GetPosition().y;
    float angle = Body->GetAngle();
	
    texture->Apply();

    glPushMatrix(); // Save the current matrix state

    // Translate to the square's position
    glTranslatef(x, y, 0.0f);

    // Apply the rotation (angle in radians converted to degrees)
    glRotatef(angle * 180.0f / 3.14159f, 0.0f, 0.0f, 1.0f); // Rotate around the Z-axis (2D rotation)

    // Render the square
    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(-width / 2.f, -height / 2.f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(width / 2.f, -height / 2.f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(width / 2.f, height / 2.f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(-width / 2.f, height / 2.f);

    glEnd();

    glPopMatrix(); // Restore the original matrix state
}