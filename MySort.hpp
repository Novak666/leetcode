#ifndef MYSORT_HPP_INCLUDED
#define MYSORT_HPP_INCLUDED

using namespace std;

void Randomize(int data[], int length)
{
    srand((unsigned)time(NULL));        //使用系统定时计数器的值做为随机种子

    for (int i = 1; i < length + 1; i++)
        data[i] = rand();
}

void Print(int data[], int length)
{
    for (int i = 1; i < length + 1; i++)
        cout << data[i] << ' ';
    cout << endl;
}

void Copy(int data[], int temp[], int length)
{
    for (int i = 1; i < length + 1; i++)
        temp[i] = data[i];
}

//直接插入排序
void InsertSort(int data[], int length)
{
    int i, j;
    for(i = 2; i <= length; i++)
        if(data[i] < data[i-1])
        {
            data[0] = data[i];
            data[i] = data[i-1];
            for(j = i - 2; data[0] < data[j]; j--)
                data[j + 1] = data[j];
            data[j + 1] = data[0];
        }
}

//折半插入排序
void BInsertSort(int data[], int length)
{
    int i, j, low, high, m;
    for(i = 2; i <= length; i++)
    {
        data[0] = data[i];
        low = 1; high = i - 1;
        while(low <= high)
        {
            m = (low + high) / 2;
            if(data[0] < data[m])
                high = m - 1;
            else
                low = m + 1;
        }
        for(j = i - 1; j >= high + 1; --j)
            data[j + 1] = data[j];
        data[high + 1] = data[0];
    }
}

//希尔排序
void ShellSort(int data[], int length, int delta[], int delta_l)
{
    int i, j;
    for(int k = 0; k < delta_l; k++)
        for(i = delta[k] + 1; i <= length; ++i)
            if(data[i] < data[i - delta[k]])
            {
                data[0] = data[i];
                data[i] = data[i - delta[k]];
                for(j = i - 2 * delta[k]; (j > 0) && (data[0] < data[j]); j = j - delta[k])
                    data[j + delta[k]] = data[j];
                data[j + delta[k]] = data[0];
            }
}

//冒泡排序
void BubbleSort(int data[], int length)
{
    bool change;
    for(int i = length, change = true; (i > 1) && change; i--)
    {
        change = false;
        for(int j = 1; j < i; j++)
            if(data[j] > data[j + 1])
            {
                int temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
                change = true;
            }
    }
}

//快速排序
int Partition(int data[], int low, int high)
{
    data[0] = data[low];
    while(low < high)
    {
        while((low < high) && (data[high] >= data[0]))
            high--;
        data[low] = data[high];
        while((low < high) && (data[low] <= data[0]))
            low++;
        data[high] = data[low];
    }
    data[low] = data[0];
    return low;
}

void QSort(int data[], int low, int high)
{
    if(low < high)
    {
        int loc = Partition(data, low, high);
        QSort(data, low, loc - 1);
        QSort(data, loc + 1, high);
    }
}

void QuickSort(int data[], int length)
{
    QSort(data, 1, length);
}

//简单选择排序
void SelectSort(int data[], int length)
{
    for(int i = 1; i < length; i++)
    {
        int min = i;
        for(int j = i; j < length + 1; j++)
            if(data[j] < data[min])
                min = j;
        if(min != i)
        {
            data[0] = data[i];
            data[i] = data[min];
            data[min] = data[0];
        }
    }
}

//堆排序
void HeapAdjust(int data[], int a, int b)
{
    data[0] = data[a];
    for(int i = 2 * a; i <= b; i *= 2)
    {
        if((i < b) && (data[i] < data[i+1]))
            i++;
        if(data[0] > data[i])
            break;
        else
        {
            data[a] = data[i];
            a = i;
        }
    }
    data[a] = data[0];
}

void HeapSort(int data[], int length)
{
    for(int i = length / 2; i > 0; i--)
        HeapAdjust(data, i, length);         //调整为大顶堆
    for(int i = length; i > 1; i--)
    {
        data[0] = data[1];
        data[1] = data[i];
        data[i] = data[0];
        HeapAdjust(data, 1, i-1);
    }
}
#endif // MYSORT_HPP_INCLUDED
