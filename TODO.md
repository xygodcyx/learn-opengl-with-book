[x]First window

[]Hello Triangle [你好，三角形](https://learnopengl-cn.github.io/01%20Getting%20started/04%20Hello%20Triangle/)
indices 的类型一定是unsigned int，不能误写为float，这些是一一对应的，与下文中的*glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);*

VAO VBO EBO/IBO

ebo绑定到最近的vao上，vbo是全局的数据，只是数据而已，它有什么用取决于vao和具体的program里的shader，而vao会在glVertexAttribPointer的时候引用最近的vbo
