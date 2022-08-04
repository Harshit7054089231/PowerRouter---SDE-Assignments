#include <bits/stdc++.h>
using namespace std;



void solve(queue<char>old_task_queue,int current_index,queue<char>new_task_queue)
{
    int index = 1;

    unordered_map<char,int>mp;

    //REACHING THE - Current Index Member and counting the frequency of elements for future use and storing in map
    while(index != current_index)
    {
        char ch = old_task_queue.front();
        old_task_queue.pop();
        mp[ch]++;
        index++;
    }

    //SAVING THE - Current Index Member
    char element = old_task_queue.front();
    mp[element]++;
    old_task_queue.pop();

    //SAVING THE - next element of Current Index Member
    char next_element = old_task_queue.front();
    mp[next_element]++;

    
    //temporary vector for storing elements
    vector<char>temp;


    //storing all elements of new task queue in temp
    while(!new_task_queue.empty())
    {
        temp.push_back(new_task_queue.front());
        new_task_queue.pop();
    }

    

    //searching for the Current Index Member new index
    int count = 0;
    for(int i=0; i<temp.size(); i++)
    {
        if(temp[i] == element)
        count++;

        if(count == mp[element])
        {
            cout<<"hello1";
            cout<<i+1;
            return;
        }   
    }

    //searching for the index of next element of Current Index Member
    count = 0;
    for(int i=0; i<temp.size(); i++)
    {
        if(temp[i] == next_element)
        count++;

        if(count == mp[next_element])
        {
            cout<<i+1;
            break;
        }   
    }




}


int main()
{



    queue<char>q1;
    queue<char>q2;

    
    q1.push('A');
    q1.push('B');
    q1.push('C');
    q1.push('D');
    q1.push('E');
    q1.push('F');
    q1.push('A');
    q1.push('B');
    q1.push('C');
    q1.push('D');
    q1.push('A');
    q1.push('B');
    q1.push('C');
    q1.push('A');
    q1.push('B');
    q1.push('A');



    q2.push('B');
    q2.push('C');
    q2.push('E');
    q2.push('F');
    q2.push('B');
    q2.push('C');
    q2.push('B');
    q2.push('C');
    q2.push('B');

    solve(q1,7,q2);


    return 0;
}