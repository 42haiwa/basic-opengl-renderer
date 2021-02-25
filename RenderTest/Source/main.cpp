//
// Created by cleme on 25/02/2021.
//

#include "Application.h"

int main()
{
    Rt::Application app;

    Rt::ApplicationCreateInfo applicationCreateInfo{};
    applicationCreateInfo.p_displayWindowCreateInfo.width = 1280;
    applicationCreateInfo.p_displayWindowCreateInfo.height = 720;
    applicationCreateInfo.p_displayWindowCreateInfo.title = "Hello";
    app.Initialize(&applicationCreateInfo);

    app.Run();

    return 0;
}
