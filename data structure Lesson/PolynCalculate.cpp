#include <iostream>
using namespace std;

// 定义多项式的项
typedef struct PolyNode
{
    float coef;     // 系数
    int expn;       // 指数
    PolyNode *next; // 指向下一项的指针
} *Polynomial;

// 创建多项式
void CreatePoly(Polynomial &P, int m)
{
    P = new PolyNode; // 创建头结点
    P->next = NULL;
    Polynomial q = P; // q指向尾结点
    for (int i = 0; i < m; i++)
    {
        float coef;
        int expn;
        cin >> coef >> expn;
        if (coef == 0)
            continue; // 系数为0则不创建结点
        Polynomial s = new PolyNode;
        s->coef = coef;
        s->expn = expn;
        s->next = NULL;
        q->next = s;
        q = s;
    }
}

// 销毁多项式
void DestroyPoly(Polynomial &P)
{
    Polynomial q;
    while (P)
    {
        q = P->next;
        delete P;
        P = q;
    }
}

// 打印多项式
void PrintPoly(Polynomial P)
{
    if (!P->next)
    {
        cout << "0" << endl;
        return;
    }
    while (P->next)
    {
        P = P->next;
        cout << P->coef << "X^" << P->expn;
        if (P->next)
            cout << " ";
    }
    cout << endl;
}

// 多项式相加
void AddPoly(Polynomial &Pa, Polynomial &Pb)
{
    Polynomial p = Pa->next, q = Pb->next, r = Pa; // 初始化三个指针，p指向Pa的第一个非零项，q指向Pb的第一个非零项，r指向Pa的头结点
    while (p && q) // 只要p和q都不为空
    {
        if (p->expn == q->expn) // 如果p和q的指数相等
        {
            float sum = p->coef + q->coef; // 将p和q的系数相加
            if (sum != 0) // 如果和不为0
            {
                p->coef = sum; // 将和赋值给p的系数
                r = p; // r指向p
                p = p->next; // p指向Pa的下一项
                q = q->next; // q指向Pb的下一项
            }
            else // 如果和为0
            {
                r->next = p->next; // 将p从Pa中删除
                delete p;
                p = r->next; // p指向Pa的下一项
                q = q->next; // q指向Pb的下一项
            }
        }
        else if (p->expn < q->expn) // 如果p的指数小于q的指数
        {
            r->next = p; // 将p插入到Pa中
            r = p; // r指向p
            p = p->next; // p指向Pa的下一项
        }
        else // 如果p的指数大于q的指数
        {
            Polynomial s = new PolyNode; // 创建一个新结点s
            s->coef = q->coef; // 将q的系数赋值给s的系数
            s->expn = q->expn; // 将q的指数赋值给s的指数
            s->next = p; // 将s插入到Pa中
            r->next = s;
            r = s; // r指向s
            q = q->next; // q指向Pb的下一项
        }
    }
    while (q) // 如果q不为空
    {
        Polynomial s = new PolyNode; // 创建一个新结点s
        s->coef = q->coef; // 将q的系数赋值给s的系数
        s->expn = q->expn; // 将q的指数赋值给s的指数
        s->next = NULL; // 将s插入到Pa的末尾
        r->next = s;
        r = s; // r指向s
        q = q->next; // q指向Pb的下一项
    }
    Pb->next = NULL; // 将Pb清空
}

// 多项式相减 与相加完全相同。
void SubtractPoly(Polynomial &Pa, Polynomial &Pb)
{
    Polynomial p = Pa->next, q = Pb->next, r = Pa;
    while (p && q)
    {
        if (p->expn == q->expn)
        {
            float diff = p->coef - q->coef;// 将p和q的系数相减
            if (diff != 0)
            {
                p->coef = diff;
                r = p;
                p = p->next;
                q = q->next;
            }
            else
            {
                r->next = p->next;
                delete p;
                p = r->next;
                q = q->next;
            }
        }
        else if (p->expn < q->expn)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        {
            Polynomial s = new PolyNode;
            s->coef = -q->coef;
            s->expn = q->expn;
            s->next = p;
            r->next = s;
            r = s;
            q = q->next;
        }
    }
    while (q)
    {
        Polynomial s = new PolyNode;
        s->coef = -q->coef;
        s->expn = q->expn;
        s->next = NULL;
        r->next = s;
        r = s;
        q = q->next;
    }
    Pb->next = NULL;
}

// 多项式相乘

// 多项式相乘
void MultiplyPoly(Polynomial &Pa, Polynomial &Pb)
{
    // 初始化变量
    Polynomial p = Pa->next, q, r, s, t = Pb->next, u = new PolyNode;
    u->next = NULL;

    // 遍历Pb中的每一项
    while (t)
    {
        // 初始化变量
        q = p;
        r = u;

        // 遍历Pa中的每一项
        while (q)
        {
            // 计算系数和指数
            float coef = t->coef * q->coef;
            int expn = t->expn + q->expn;
            // 找到Pa中第一个指数小于等于expn的项的前一个位置
            while (r->next && r->next->expn > expn)
                r = r->next;

            // 如果Pa中存在指数等于expn的项
            if (r->next && r->next->expn == expn)
            {
                // 将两项的系数相加
                float sum = r->next->coef + coef;

                // 如果系数和不为0，则更新Pa中的项
                if (sum != 0)
                {
                    r->next->coef = sum;
                }
                // 如果系数和为0，则删除Pa中的项
                else
                {
                    s = r->next;
                    r->next = s->next;
                    delete s;
                }
            }
            // 如果Pa中不存在指数等于expn的项
            else
            {
                // 创建新的项，并插入到Pa中
                s = new PolyNode;
                s->coef = coef;
                s->expn = expn;
                s->next = r->next;
                r->next = s;
            }

            // 处理Pa中的下一项
            q = q->next;
        }

        // 处理Pb中的下一项
        t = t->next;
    }

    // 清空Pb
    Pb->next = NULL;

    // 将结果存储到Pa中
    Pa->next = u->next;

    // 释放内存
    delete u;
}



int main()
{   
    system("chcp 65001"); // 设置控制台编码为UTF-8
    Polynomial P1, P2;
    int m, n;
    cin >> m;
    CreatePoly(P1, m); // 创建多项式P1
    cin >> n;
    CreatePoly(P2, n); // 创建多项式P2
    cout << "请选择要进行的操作：\n"
         << "1.相加\n"
         << "2.相减\n"
         << "3.相乘\n";
    int op;
    cin >> op;
    if (op == 1)
    {
        AddPoly(P1, P2); // 多项式相加
        PrintPoly(P1); // 打印相加结果
    }
    else if (op == 2)
    {
        SubtractPoly(P1, P2); // 多项式相减
        PrintPoly(P1); // 打印相减结果
    }
    else if (op == 3)
    {
        MultiplyPoly(P1, P2); // 多项式相乘
        PrintPoly(P1); // 打印相乘结果
    }
    DestroyPoly(P1); // 销毁多项式P1
    DestroyPoly(P2); // 销毁多项式P2
    return 0;
}
/*
4
1 3
1 2
1 1
1 0
4
2 3
2 2
2 1
2 0

示例输入
*/
