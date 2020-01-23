#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image_aug.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <mesh.h>
#include <shader.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <cfloat>
#include "Bala.h"

using namespace std;

const float movSpeed = 0.002f;

Bala::Bala() {
	this->posicionActual = glm::vec3(0, 0, 0);
	this->velocidadActual = glm::vec3(0, 0, 0);
	this->direccion = glm::vec3(0, 0, 0);
	this->disparado = false;
	this->moviendose = false;
	this->recargado = false;
}
Bala::Bala(glm::vec3 posicionActual, glm::vec3 velocidadActual, glm::vec3 direccion, bool disparado, bool moviendose, bool recargado) {
	this->posicionActual = posicionActual;
	this->velocidadActual = velocidadActual;
	this->direccion = direccion;
	this->disparado = disparado;
	this->moviendose = moviendose;
	this->recargado = recargado;
}
glm::mat4 Bala::render() {
	//printf("-----\n");
	//printf("\n\n");

	//printf("Bala x: %f , Bala y: %f ,Bala z: %f\n", this->posicionActual.x, this->posicionActual.y, this->posicionActual.z);
	//glm::vec3 nuevo = this->direccion*0.005f;
	//this->posicionActual = nuevo;
	glm::mat4 modBala =
		glm::translate(glm::mat4(1.0f), glm::vec3(this->posicionActual.x + 0.0005f, this->posicionActual.y - 0.0005f, this->posicionActual.z)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f)) *
		glm::scale(glm::mat4(1.0f), glm::vec3(0.00002f, 0.00002f, 0.00002f));
	//this->posicionActual.x -= 0.002f;
	//printf("DESPUES Bala x: %f , Bala y: %f ,Bala z: %f\n", this->posicionActual.x, this->posicionActual.y, this->posicionActual.z);
	return modBala;
}

void Bala::actualizarPosicion() {
	//this->posicionActual += this->direccion*0.5f;
	this->posicionActual += this->direccion*movSpeed;
}