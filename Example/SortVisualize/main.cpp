#include "window.h"
#include "event.h"
#include "Renderer.h"
#include "BufferManager.h"

#include "Rectangle/Rectangle.hpp"


// Функция будет менять их расположение и размер оставяя всё остальное прежним
void SwapShape(Rectangle* rect, Rectangle* rect2){
    float Temp = rect->getPosition().x;
    rect->setPosition( glm::vec2(rect2->getPosition().x, rect->getPosition().y) );
    rect2->setPosition( glm::vec2(Temp, rect2->getPosition().y) );
}



void Generate(std::vector<Rectangle*>& data, std::size_t Size){
    float d = 1.0f / Size;
    for(int i = 1; i < Size; ++i){
        float height = d * i;
        float yCoord = -1.0f + height / 2.0f;
        float xCoord = -1.0f + d * 2.0f * i;

        data.push_back( new Rectangle(glm::vec2(xCoord, yCoord), glm::vec2(d, height)) );
    }
}


void Random(std::vector<Rectangle*>& data){
    for(int i = 0; i < data.size(); ++i){
        int randIndex = rand() % (data.size() - 1);
        SwapShape(data[i], data[ randIndex ]);
        std::swap(data[i], data[ randIndex ]);
    }
}


bool isSorted(std::vector<Rectangle*> data){
    for(int i = 0; i < data.size() - 1; ++i)
        if(data[i]->getSize().y > data[i + 1]->getSize().y)
            return false;
    return true;
}


int main(int args, char** argv){
    assert(window::initialization("BubbleSort Visualizator", 900, 900) == true);
    Renderer::initialization();
    event::init();
    window::setIcon("sorticon.png");

    std::cout << "It's Bubble Sort Visualizator" << std::endl;
    std::vector<Rectangle*> data;
    srand(time(0));
    int count = 2;
    std::cout << "Enter the number of items: ";
    std::cin >> count;
    
    Generate(data, count);
    Random(data);

    
    int i = 0;
    bool isSort = false;

    while(!window::isShouldCloseWindow()){
        window::clear(glm::vec4(BLACK, 1.0f));

        // рендер
        Renderer::render();
            
        if(!isSort){
            i = i % (data.size() - 1);
            if(data[i]->getSize().y > data[i + 1]->getSize().y){
                data[i]->setColor(RED);
                SwapShape(data[i], data[i + 1]);
                std::swap(data[i], data[i + 1]);
            }
            data[i]->setColor(WHITE);
            ++i;
            isSort = isSorted(data);
            if(isSort){
                std::cout << "\033[92mSorting finished!\033[0m" << std::endl;
                data[i]->setColor(WHITE);
            }
        }

        // другого выхода не нашёл
        data[data.size() - 1]->setColor(WHITE);

        // проверка на выход
        if(event::jKeyPressed(GLFW_KEY_Q))
            window::setShouldCloseWindow(true);
        

        window::swapBuffers();
        event::update();
    }
    

    // очистка памяти
    for(Rectangle* _iter : data)
        delete _iter;

    // очистка всех ресурсов
    BufferManager::finallization();
    Renderer::finalization();
    event::free();
    window::finallyzation();
}
