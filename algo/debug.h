#include <bits/stdc++.h>
unordered_map<int, int> kjhhgffsasd;
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s)
{
    return '"' + s + '"';
}

string to_string(char t)
{
    return "'" + string({ t }) + "'";
}

string to_string(const char* s)
{
    return to_string((string)s);
}

string to_string(bool b)
{
    return (b ? "true" : "false");
}

string to_string(vector<bool> v)
{
    bool first = true;
    string res = "{";
    for(int i = 0; i < static_cast<int>(v.size()); i++)
    {
        if(!first)
        {
            res += ",";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v)
{
    string res = "";
    for(size_t i = 0; i < N; i++)
    {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for(const auto& x : v)
    {
        if(!first)
        {
            res += ",";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p)
{
    return "(" + to_string(p.first) + "," + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p)
{
    return "(" + to_string(get<0>(p)) + "," + to_string(get<1>(p)) + "," + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p)
{
    return "(" + to_string(get<0>(p)) + "," + to_string(get<1>(p)) + "," + to_string(get<2>(p)) + "," + to_string(get<3>(p)) + ")";
}

vector<string> vec_splitter(string s)
{
    s += ',';
    remove(s.begin(), s.end(), ' ');
    vector<string> res;
    while(!s.empty())
    {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(
    vector<string> __attribute__((unused)) args,
    __attribute__((unused)) int idx,
    __attribute__((unused)) int LINE_NUM)
{
    clog << endl;
}

template <typename T, size_t size>
void print(const T(&array)[size], int LINE_NUM)
{
    clog << "[" << LINE_NUM << "]" << "[" << ++kjhhgffsasd[LINE_NUM] << "] {";
    for(size_t i = 0; i < size; ++i)
    {
        clog << array[i] << ((i < size - 1) ? "," : "");
    }
    clog << "}" << endl;
}

template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T)
{
    if(idx > 0)
        clog << endl << "[" << LINE_NUM << "]" << "[" << kjhhgffsasd[LINE_NUM] << "] ";
    else
        clog << "[" << LINE_NUM << "]" << "[" << ++kjhhgffsasd[LINE_NUM] << "] ";
    // stringstream ss; ss << H;
    clog << args[idx] << ":" << to_string(H);
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__);
#define dclear(x) dclear_out(x);
#define print(x) print(x, __LINE__);

void dclear_out(int I)
{
    kjhhgffsasd.clear();
    clog << "-------" << I << "-------" << endl;
}

// ____________________________________________________________________________________________________________________________________

// void debug_out() { clog << endl; }

// template <typename Head, typename... Tail>
// void debug_out(Head H, Tail... T) {
//   clog << to_string(H)<<"";
//   debug_out(T...);
// }

// #define debug(...) clog << "[" << __LINE__ <<"] "<< #__VA_ARGS__<<" : |" , debug_out(__VA_ARGS__);

// template<typename T>
// int SIZE(T (&t)){
//     return t.size();
// }

// template<typename T, size_t N>
// int SIZE(T (&t)[N]){
//     return N;
// }

// string to_string(char t){
//     return "'" + string({t}) + "'";
// }

// string to_string(bool t){
//     return t ? "true" : "false";
// }

// string to_string(const string &t, int x1=0, int x2=1e9){
//     string ret = "";
//     for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){
//         ret += t[i];
//     }
//     return '"' + ret + '"';
// }

// string to_string(const char* t){
//     string ret(t);
//     return to_string(ret);
// }

// template<size_t N>
// string to_string(const bitset<N> &t, int x1=0, int x2=1e9){
//     string ret = "";
//     for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){
//         ret += t[i] + '0';
//     }
//     return to_string(ret);
// }

// template<typename T, typename... Coords>
// string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C);

// template<typename T, typename S>
// string to_string(const pair<T, S> &t){
//     return "(" + to_string(t.first) + ", " + to_string(t.second) + ")";
// }

// template<typename T, typename... Coords>
// string to_string(const T (&t), int x1, int x2, Coords... C){
//     string ret = "[";
//     x1 = min(x1, SIZE(t));
//     auto e = begin(t);
//     advance(e,x1);
//     for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){
//         ret += to_string(*e, C...) + (i != _i ? ", " : "");
//         e = next(e);
//     }
//     return ret + "]";
// }

// template<int Index, typename... Ts>
// struct print_tuple{
//     string operator() (const tuple<Ts...>& t) {
//         string ret = print_tuple<Index - 1, Ts...>{}(t);
//         ret += (Index ? ", " : "");
//         return ret + to_string(get<Index>(t));
//     }
// };

// template<typename... Ts>
// struct print_tuple<0, Ts...> {
//     string operator() (const tuple<Ts...>& t) {
//         return to_string(get<0>(t));
//     }
// };

// template<typename... Ts>
// string to_string(const tuple<Ts...>& t) {
//     const auto Size = tuple_size<tuple<Ts...>>::value;
//     return print_tuple<Size - 1, Ts...>{}(t);
// }

// void dbgr(){;}
// template<typename Heads, typename... Tails>
// void dbgr(Heads H, Tails... T){
//     cout << to_string(H) << " | ";
//     dbgr(T...);
// }

// void dbgs(){;}
// template<typename Heads, typename... Tails>
// void dbgs(Heads H, Tails... T){
//     cout << H << " ";
//     dbgs(T...);
// }

// /*
// formatted functions:
// */

// /*
// consider __VA_ARGS__ as a whole:
// dbgv() prints values only
// dbg() prints name and values
// */
// #define dbgv(...) cout << to_string(__VA_ARGS__) << endl;

// #define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);

// /*
// consider __VA_ARGS__ as a sequence of arguments:
// dbgr() prints values only
// dbgm() prints names and values
// */
// #define dbgr(...) dbgr(__VA_ARGS__); cout << endl;

// #define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);

// /*
// dbgs() prints only values separated by spaces
// */
