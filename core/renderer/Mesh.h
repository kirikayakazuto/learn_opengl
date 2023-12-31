//
// Created by 邓朗 on 2024/1/4.
//

#ifndef LEARN_OPENGL_MESH_H
#define LEARN_OPENGL_MESH_H

#include <glad/glad.h>
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <memory>
#include <GLFW/glfw3.h>


struct AttributeFormat {
    std::string name;
    unsigned int num;
};

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 color;
    glm::vec2 uv;
};

class Mesh {

private:
    bool dirty;

    GLuint VAO_ID;
    GLuint VBO_ID;
    GLuint EBO_ID;

public:
    std::unique_ptr<std::vector<Vertex>> vertices;
    std::unique_ptr<std::vector<GLuint>> indices;
    std::unique_ptr<std::vector<AttributeFormat>> attribute_info;

    Mesh(std::vector<AttributeFormat>& attribute_data, std::vector<Vertex>& v_data, std::vector<GLuint>& i_data);

    void Upload();

    void Draw();
};


#endif //LEARN_OPENGL_MESH_H
