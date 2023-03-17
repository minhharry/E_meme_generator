#include <bits/stdc++.h>

using namespace std;
map<string, int> mp;
vector<string> a;
const string E_MEME = "UwU";
const string randstr = "oqn4234c2a37289";
int main ()
{
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    string s;
    while (getline(cin, s))
    {
        if (s[0]=='#')
        {
            cout << s << endl;
        }
        else
        {
            string s2 = s;
            s = regex_replace(s,regex(";"), " ; ");
            s = regex_replace(s,regex(","), " , ");
            s = regex_replace(s,regex("\\."), " . ");
            s = regex_replace(s,regex("\\*"), " * ");
            s = regex_replace(s,regex("\\/"), " / ");
            s = regex_replace(s,regex("\\("), " ( ");
            s = regex_replace(s,regex("\\)"), " ) ");
            s = regex_replace(s,regex("\\["), " [ ");
            s = regex_replace(s,regex("\\]"), " ] ");
            s = regex_replace(s,regex("\\{"), " { ");
            s = regex_replace(s,regex("\\}"), " } ");

            s = regex_replace(s,regex("\\+\\+"), randstr);
            s = regex_replace(s,regex("\\+"), " + ");
            s = regex_replace(s,regex(randstr), " ++ ");

            s = regex_replace(s,regex("\\-\\-"), randstr);
            s = regex_replace(s,regex("\\-"), " - ");
            s = regex_replace(s,regex(randstr), " -- ");

            s = regex_replace(s,regex("::"), randstr);
            s = regex_replace(s,regex(":"), " : ");
            s = regex_replace(s,regex(randstr), " :: ");

            s = regex_replace(s,regex("<<"), randstr);
            s = regex_replace(s,regex("<"), " < ");
            s = regex_replace(s,regex(randstr), " << ");

            s = regex_replace(s,regex(">>"), randstr);
            s = regex_replace(s,regex(">"), " > ");
            s = regex_replace(s,regex(randstr), " >> ");
            stringstream ss(s);
            string x = "";
            while (ss >> x)
            {
                if (x[0]=='"')
                {
                    size_t pos = s2.find("\""); // find first quotation mark
                    s2[pos] = '_';
                    if (pos != std::string::npos)
                    {
                        size_t end_pos = s2.find("\"", pos + 1); // find second quotation mark
                        if (end_pos != std::string::npos)
                        {
                            x = s2.substr(pos + 1, end_pos - pos - 1); // extract the substring
                        }
                        s2[end_pos] = '_';
                    }
                    x = '"' + x + '"';
                    string temp;
                    ss >> temp;
                    while (temp[temp.size()-1]!='"' && (ss >> temp));
                }
                if (x=="") continue;
                ++mp[x];
                a.push_back(x);
            }
            a.push_back("\n");
        }
    }
    vector<pair<int, string>> b;
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        b.push_back(make_pair(it->second,it->first));
    }




    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    //srand(time(NULL));
    //random_shuffle(b.begin(), b.end());


    for (int i = 0; i<b.size(); ++i)
    {
        mp[b[i].second] = i+1;
        cerr << b[i].second << ' ' << i+1 << endl;
        cout << "#define ";
        //////////cout << 'e' << i+1 << ' ';
        for (int j = 0; j<i+1; ++j) cout << E_MEME;
        cout << ' ' << b[i].second << endl;
    }

    for (int i = 0; i<a.size(); ++i)
    {
        if (a[i]=="\n")
        {
            cout << endl;
            continue;
        }
        for (int j = 0; j<mp[a[i]]; ++j) cout << E_MEME;
        ////////////cout << 'e' << mp[a[i]];
        cout << ' ';// cout << a[i]; cout << ' ';
    }
   /* for (int i = 0; i<a.size(); ++i)
    {
        cout << a[i] <<  ' ';
    }*/
    return 0;
}






