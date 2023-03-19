#include <bits/stdc++.h>

using namespace std;
map<string, int> mp;
vector<string> a;
const string E_MEME = "e";
const string randstr = "oqn4234c2a37289";
const bool LongE = true;
bool cmp(pair<string, int> a, pair<string, int> b)
{
    if (a.second==b.second)
    {
        return (a.first < b.first);
    }
    return (a.second > b.second);
}
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
            s = regex_replace(s,regex("\\("), " ( ");
            s = regex_replace(s,regex("\\)"), " ) ");
            s = regex_replace(s,regex("\\["), " [ ");
            s = regex_replace(s,regex("\\]"), " ] ");
            s = regex_replace(s,regex("\\{"), " { ");
            s = regex_replace(s,regex("\\}"), " } ");

            s = regex_replace(s,regex("\\+\\+"), " ++ ");

            s = regex_replace(s,regex("\\-\\-"), " -- ");


            s = regex_replace(s,regex("::"), randstr);
            s = regex_replace(s,regex(":"), " : ");
            s = regex_replace(s,regex(randstr), " :: ");


            s = regex_replace(s,regex("=="), " == ");
            s = regex_replace(s,regex("!="), " != ");
            s = regex_replace(s,regex("<<"), " << ");
            s = regex_replace(s,regex(">>"), " >> ");
            s = regex_replace(s,regex("//"), " // ");
            s = regex_replace(s,regex("&&"), " && ");
            s = regex_replace(s,regex("\\|\\|"), " || ");
            s = regex_replace(s, regex("\"([^\"]*)\""), " \"$1\" ");
            s = regex_replace(s, regex("'([^']*)'"), " '$1' ");

            stringstream ss(s);
            string x = "";
            string xx = "";
            while (ss >> x)
            {
                xx = x;
                char quote = 0;
                if (x[0]=='\"') quote = '\"';
                if (x[0]=='\'') quote = '\'';
                if (x[0]==quote)
                {
                    string temp = x;
                    size_t pos = s2.find(quote); // find first quotation mark
                    if (pos != std::string::npos)
                        s2[pos] = '_';
                    if (pos != std::string::npos)
                    {
                        size_t end_pos = s2.find(quote, pos + 1); // find second quotation mark
                        if (end_pos != std::string::npos)
                        {
                            x = s2.substr(pos + 1, end_pos - pos - 1); // extract the substring
                            s2[end_pos] = '_';
                        }
                    }
                    xx = quote + x + quote;
                    if (temp=="") continue;
                    pos = temp.find(quote); // find first quotation mark
                    if (pos != std::string::npos)
                        temp[pos] = '_';
                    while (temp.find(quote)==string::npos && (ss >> temp));
                }
                if (xx=="") continue;
                ++mp[xx];
                a.push_back(xx);
            }
            a.push_back("\n");
        }
    }
    vector<pair<string, int>> b;
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        b.push_back(make_pair(it->first,it->second));
    }




    sort(b.begin(), b.end(), cmp);
    //srand(time(NULL));
    //random_shuffle(b.begin(), b.end());


    for (int i = 0; i<b.size(); ++i)
    {
        mp[b[i].first] = i+1;
        cerr << b[i].first << ' ' << i+1 << endl;
        cout << "#define ";
        if (!LongE)
            cout << 'e' << i+1 << ' ';
        else
        {
            for (int j = 0; j<i+1; ++j) cout << E_MEME;
        }
        cout << ' ' << b[i].first << endl;
    }

    for (int i = 0; i<a.size(); ++i)
    {
        if (a[i]=="\n")
        {
            cout << endl;
            continue;
        }
        if (a[i]=="//")
        {
            cout << "// ";
            continue;
        }
        if (!LongE)
            cout << 'e' << mp[a[i]];
        else
            for (int j = 0; j<mp[a[i]]; ++j) cout << E_MEME;
        cout << ' ';// cout << a[i]; cout << ' ';
    }
    /* for (int i = 0; i<a.size(); ++i)
     {
         cout << a[i] <<  ' ';
     }*/
    return 0;
}






