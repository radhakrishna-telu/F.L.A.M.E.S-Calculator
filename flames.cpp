#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>
int cutting(int n, int k)
{
    if (k == 0)
        return n - 1;
    if (n == 1)
        return 0;
    return (cutting(n - 1, k) + k) % n;
}
void freq(string a, int n, string b, int m)
{
    unordered_map<char, int> h1;
    unordered_map<char, int> h2;
    for (int i = 0; i < n; i++)
        h1[a[i]]++;

    for (int i = 0; i < m; i++)
    {
        if (h1.find(b[i]) == h1.end())
            h2[b[i]]++;

        else if (h1[b[i]] > 0)
            h1[b[i]]--;

        if (h1[b[i]] == 0)
            h1.erase(b[i]);
    }
    int k = 0;
    for (auto it = h1.begin(); it != h1.end(); it++)
    {
        k += it->second;
    }
    for (auto it = h2.begin(); it != h2.end(); it++)
    {
        k += it->second;
    }
    string s = "flames";
    int ans = cutting(s.length(), k);
    if (s[ans] == 'f')
        cout << "Friends";
    if (s[ans] == 'l')
        cout << "Lovers";
    if (s[ans] == 'a')
        cout << "Attraction";
    if (s[ans] == 'm')
        cout << "Marriage";
    if (s[ans] == 'e')
        cout << "Enemy";
    if (s[ans] == 's')
        cout << "Siblings";
}

int main()
{
    string s1, s2;
    cout << "FLAMES calculator" << endl;
    cout << "please enter without spaces" << endl;
    cout << "enter your name: ";
    cin >> s1;
    cout << "enter your crush name: ";
    cin >> s2;
    freq(s1, s1.length(), s2, s2.length());
}