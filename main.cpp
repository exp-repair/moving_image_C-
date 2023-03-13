#include <iostream>
#include <chrono>
#include <math.h>
#include <thread>

#include <stdlib.h>
#include <unistd.h>
#include <list>
#include <vector>

using namespace std;

// 计算终端宽度
int terminal_width = 30;

// 小人的初始位置
int position = 0;

void print_running_man1(int position) {
    cout << string(position, ' ') << "   O" << endl;
    cout << string(position, ' ') << "  /|\\" << endl;
    cout << string(position, ' ') << "  / \\" << endl;
    cout <<"孤独的旅人" << std::endl;
}

void print_running_man2(int position) {
    cout << string(position, ' ') << "   O" << endl;
    cout << string(position, ' ') << "  /|\\" << endl;
    cout << string(position, ' ') << "   | " << endl;
    cout <<"孤独的旅人" << std::endl;
}

void print_running_man_with_another1(int position) {
    cout << string(position, ' ') << "   O "  << "   O "<< endl;
    cout << string(position, ' ') << "  /|\\" << "  /|\\" << endl;
    cout << string(position, ' ') << "  / \\" << "  / \\" << endl;
    cout <<"抱得美人归" << std::endl;
}

void print_running_man_with_another2(int position) {
    cout << string(position, ' ') << "   O "  << "   O " << endl;
    cout << string(position, ' ') << "  /|\\" << "  /|\\" << endl;
    cout << string(position, ' ') << "   | "  << "   | " << endl;
    cout <<"抱得美人归" << std::endl;
}

void print_running_man_wait_for_you1(int position) {
    cout << string(position, ' ') << "   O "  << string(terminal_width-position, ' ') << "   O "<< endl;
    cout << string(position, ' ') << "  /|\\" << string(terminal_width-position, ' ') << "  /|\\" << endl;
    cout << string(position, ' ') << "  / \\" << string(terminal_width-position, ' ') << "   | " << endl;
    cout <<"抱得美人归" << std::endl;
}

void print_running_man_wait_for_you2(int position)
 {
    cout << string(position, ' ') << "   O "  << string(terminal_width-position, ' ') << "   O " << endl;
    cout << string(position, ' ') << "  /|\\" << string(terminal_width-position, ' ') << "  /|\\" << endl;
    cout << string(position, ' ') << "   | "  << string(terminal_width-position, ' ') << "   | " << endl;
    cout <<"抱得美人归" << std::endl;
}

void print_running_play_with_go_cat1(int position) {
    cout << string(position, ' ') << "     "  << string(terminal_width-position, ' ') << "   /\\_/\\    "<< endl;
    cout << string(position, ' ') << "   O "  << string(terminal_width-position, ' ') << " ( o   o ) "<< endl;
    cout << string(position, ' ') << "  /|\\" << string(terminal_width-position, ' ') << "==(     )==" << endl;
    cout << string(position, ' ') << "  / \\" << string(terminal_width-position, ' ') << "  `--'--'  " << endl;
    cout <<"捉住一只猫" << std::endl;
}

void print_running_play_with_go_cat2(int position) {
    cout << string(position, ' ') << "     "  << string(terminal_width-position, ' ') << "   /\\_/\\    "<< endl;
    cout << string(position, ' ') << "   O "  << string(terminal_width-position, ' ') << " ( o   o ) "<< endl;
    cout << string(position, ' ') << "  /|\\" << string(terminal_width-position, ' ') << "==(     )==" << endl;
    cout << string(position, ' ') << "   | " << string(terminal_width-position, ' ')  << "  `--'--'  " << endl;
    cout <<"捉住一只猫" << std::endl;
}

void print_running_play_with_cat1(int position) {
    cout << string(position, ' ') << "     "  << "  /\\_/\\    "<< endl;
    cout << string(position, ' ') << "   O "  << " ( o   o ) "<< endl;
    cout << string(position, ' ') << "  /|\\" << "==(     )==" << endl;
    cout << string(position, ' ') << "  / \\" << "  `--'--'  " << endl;
    cout <<"捉住一只猫" << std::endl;
}

void print_running_play_with_cat2(int position) {
    cout << string(position, ' ') << "     "  <<  "  /\\_/\\    "<< endl;
    cout << string(position, ' ') << "   O "  << " ( o   o ) "<< endl;
    cout << string(position, ' ') << "  /|\\" << "==(     )==" << endl;
    cout << string(position, ' ') << "   | "  << "   `--'    " << endl;
    cout <<"捉住一只猫" << std::endl;
}

void clear_screen()
{
    system("clear");
}

// 定义小人的行走轨迹
void (*walk_sequence[])(int) = {print_running_man1, print_running_man2, print_running_man1};


void (*walk_sequence_with_another[])(int) = {print_running_man_with_another1, print_running_man_with_another2, print_running_man_with_another1};
void (*walk_sequence_wait_for_you[])(int) = {print_running_man_wait_for_you1, print_running_man_wait_for_you2, print_running_man_wait_for_you1};

void (*catch_a_cat[])(int) = {print_running_play_with_go_cat1, print_running_play_with_go_cat2, print_running_play_with_go_cat1};
void (*catch_a_cat_back[])(int) = {print_running_play_with_cat1, print_running_play_with_cat2, print_running_play_with_cat1};


void walkToRight()
{
    while (position < terminal_width)
    {
        for (int j = 0; j < 3; j++)
        {
            clear_screen();
            walk_sequence[j](position);
            if(j==1)
            {
                position++;
            }
            this_thread::sleep_for(chrono::milliseconds(30));
        }
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void walkToLeft()
{
    while (position > 0)
        {
            for (int j = 0; j < 3; j++)
            {
                clear_screen();
                walk_sequence[j](position);
                if(j==1)
                {
                    position--;
                }
                this_thread::sleep_for(chrono::milliseconds(30));
            }
            this_thread::sleep_for(chrono::milliseconds(100));
        }
}

void walkToRight_with_another()
{
    while (position < terminal_width)
    {
        for (int j = 0; j < 3; j++)
        {
            clear_screen();
            walk_sequence_with_another[j](position);
            if(j==1)
            {
                position++;
            }
            this_thread::sleep_for(chrono::milliseconds(30));
        }
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void walkToLeft_with_another()
{
    while (position > 0)
        {
            for (int j = 0; j < 3; j++)
            {
                clear_screen();
                walk_sequence_with_another[j](position);
                if(j==1)
                {
                    position--;
                }
                this_thread::sleep_for(chrono::milliseconds(30));
            }
            this_thread::sleep_for(chrono::milliseconds(100));
        }
}

void walkToRight_wait_for_you()
{
    while (position < terminal_width)
    {
        for (int j = 0; j < 3; j++)
        {
            clear_screen();
            walk_sequence_wait_for_you[j](position);
            if(j==1)
            {
                position++;
            }
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void walkToLeft_wait_for_you()
{
    while (position > 0)
        {
            for (int j = 0; j < 3; j++)
            {
                clear_screen();
                walk_sequence_wait_for_you[j](position);
                if(j==1)
                {
                    position--;
                }
                this_thread::sleep_for(chrono::milliseconds(30));
            }
            this_thread::sleep_for(chrono::milliseconds(100));
        }
}

void cat_a_cat_for_you()
{
    while (position < terminal_width)
    {
        for (int j = 0; j < 3; j++)
        {
            clear_screen();
            catch_a_cat[j](position);
            if(j==1)
            {
                position++;
            }
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void cat_a_cat_for_you_back()
{
    while (position > 0)
        {
            for (int j = 0; j < 3; j++)
            {
                clear_screen();
                catch_a_cat_back[j](position);
                if(j==1)
                {
                    position--;
                }
                this_thread::sleep_for(chrono::milliseconds(30));
            }
            this_thread::sleep_for(chrono::milliseconds(100));
        }
}


// 循环让小人行走
int main() {
    while (1)
    {
        // walkToRight();
        // walkToLeft();

        // walkToRight_with_another();
        // walkToLeft_with_another();

        // walkToRight_wait_for_you();
        // walkToLeft_with_another();

        cat_a_cat_for_you();
        cat_a_cat_for_you_back();
    }
    
    return 0;
}

