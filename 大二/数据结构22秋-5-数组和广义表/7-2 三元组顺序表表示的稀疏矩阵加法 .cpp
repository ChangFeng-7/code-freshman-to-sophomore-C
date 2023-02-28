#include <iostream>

using namespace std;

typedef struct
{
    int i, j, v;
} triple;

typedef struct
{
    triple data[100];
    int m, n, t;
} matrix;

int main()
{
    matrix m1, m2, m0;
    cin >> m1.m >> m1.n >> m1.t >> m2.t;
    m2.m = m1.m;
    m2.n = m1.n;
    for (int a = 0; a < m1.t; a++)
        cin >> m1.data[a].i >> m1.data[a].j >> m1.data[a].v;
    for (int b = 0; b < m2.t; b++)
        cin >> m2.data[b].i >> m2.data[b].j >> m2.data[b].v;
    int index = 0, a = 0, b = 0;
    while (a < m1.t && b < m2.t)
    {
        if (m1.data[a].i < m2.data[b].i)
            m0.data[index++] = m1.data[a++];
        else if (m1.data[a].i > m2.data[b].i)
            m0.data[index++] = m2.data[b++];
        else if (m1.data[a].j < m2.data[a].j)
            m0.data[index++] = m1.data[a++];
        else if (m1.data[a].j > m2.data[b].j)
            m0.data[index++] = m2.data[b++];
        else
        {
            m1.data[a].v += m2.data[b].v;
            if (m1.data[a].v)
                m0.data[index++] = m1.data[a];
            a++;
            b++;
        }
    }
    for (int i = a; i < m1.t; i++)
        m0.data[index++] = m1.data[i];
    for (int i = b; i < m2.t; i++)
        m0.data[index++] = m2.data[i];
    cout << m1.m << ' ' << m1.n << ' ' << index << endl;
    for (int i = 0; i < index; i++)
    {
        if (i)
            cout << endl;
        cout << m0.data[i].i << ' ' << m0.data[i].j << ' ' << m0.data[i].v;
    }
    return 0;
}