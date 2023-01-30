#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "log.h"

int main()
{
    Logger logger;
    logger << "Hello World!";
    return 0;
}