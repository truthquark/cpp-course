#include <iostream>
#include <Stack.cpp>

#define TEST(what,cond)\
    if (cond())                 \
        cout << "Test passed!" << endl; \
    else                        \
        cout << "Test not passed!" << endl; \

#define ASSERT_EQ(cond1,cond2)  \
    if (cond1!=cond2)           \
        assert(0);              \

#define EXCEPT_EQ(cond1,cond2)  \
    if (cond1!=cond2)           \
        return false;           \

bool PushSingleNumber()
{
    Stack s;
    s.push(3802);
    EXCEPT_EQ(s.top(), 0xEDA);
    s.pop();
    EXCEPT_EQ(s.empty(), true);
    return true;
}

bool CheckDestroyedStack()
{
    Stack *p;
    {
        Stack s;
        for (int i = 0; i < s.capacity(); i++)
            s.push(100 + i);
        p = &s;
    }
    EXCEPT_EQ(p->ok(), false);
    return true;
}

bool CannotPushMore()
{
    Stack s;
    for (int i = 0; i < s.capacity(); i++)
        s.push(100 + i);
    EXCEPT_EQ(s.push(0xF00D), false);
    return true;
}


int main()
{
    TEST(Stack, PushSingleNumber);
    TEST(Stack, CannotPushMore);
    TEST(Stack, CheckDestroyedStack);

    Stack *p1;
    {
        Stack s1(8);
        s1.push(10);
        s1.push(9);
        s1.push(8);
        s1.push(7);
        s1.push(6);
        s1.pop();
        s1.pop();
        s1.dump();
        cout << s1.top() << endl;
        p1 = &s1;
    }
    (*p1).dump();

    Stack s2(15);
    s2.push(1);
    s2.dump();
    s2.pop();
    s2.dump();

    return 0;
}
