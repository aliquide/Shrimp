
GLuint LoadBMP(const char *fileName)
{
	FILE *file;
	unsigned char header[54];
	unsigned int dataPos;
	unsigned int size;
	unsigned int width, height;
	unsigned char *data;


	file = fopen(fileName, "rb");

	if (file == NULL){
		printf("brak pliku.");
		return false;
	}

	if (fread(header, 1, 54, file) != 54){
		return false;
	}

	if (header[0] != 'B' || header[1] != 'M'){
		return false;
	}

	dataPos = *(int*)&(header[0x0A]);
	size = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	if (size == NULL)
		size = width * height * 3;
	if (dataPos == NULL)
		dataPos = 54;

	data = new unsigned char[size];

	fread(data, 1, size, file);

	fclose(file);

	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	return texture;
}