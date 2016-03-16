#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#define GBUFFER_SIZE 4
#define DIFFUSE 0
#define NORMAL 1
#define LIGHT 3
#define DEPTH 2 
#define NULL 0

#define POSTFX_SIZE 2
#define BACK_BUFFER 0
#define FRONT_BUFFER 1


#include "utility.h"
#include <gl/glew.h>


class Framebuffer{
public:
	unsigned int width;
	unsigned int height;
	unsigned int numOfColorAttachments;
	unsigned int numOfDepthAttachments;
	GLuint handle;
	GLuint* textures;
	GLenum* colorAttachments;
	GLenum format;
	Framebuffer(GLint _width, GLint _height, unsigned int _numOfColorAttachments, GLenum _format, unsigned int _numOfDepthAttachments);
	~Framebuffer();
	void Init();
	void Bind();
	void Unbind();
	void BindAttachments(GLint size, GLenum* attachments);
	void BindAttachment(GLenum attachment);
	void BindDepthAttachment(GLenum level);
	void Clear(GLbitfield clearMask);

};


class GBuffer : public Framebuffer{

	GBuffer();
	~GBuffer();

};




#endif