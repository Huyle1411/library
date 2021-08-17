namespace Color {
enum Code {
    FG_RED = 31,
    FG_GREEN = 32,
    FG_YELLOW = 33,
    FG_BLUE = 34,
    FG_DEFAULT = 39
};
class ColorDebugger {
    Code code;

   public:
    ColorDebugger(Code pCode) : code(pCode) {}
    template <class T>
    ColorDebugger &operator<<(const T &other) {
        cout << "\033[" << code << "m" << other << "\033[" << FG_DEFAULT << "m";
        return *this;
    }
    ColorDebugger &operator<<(ostream &(*pManip)(ostream &)) {
        (*pManip)(cout);
        return *this;
    }
};
}  // namespace Color

using namespace Color;
ColorDebugger ycerr(FG_YELLOW);
ColorDebugger rcerr(FG_RED);
ColorDebugger bcerr(FG_BLUE);
ColorDebugger gcerr(FG_GREEN);

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char *s) {
    return to_string((string)s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    gcerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef _DEBUG
#define debug(...) rcerr << "LINE(" << __LINE__ << ") [" << __FUNCTION__ << "] -> " \
                         << "[" << #__VA_ARGS__ << "]:",                            \
                   debug_out(__VA_ARGS__)
#else
#define debug(...) 95
#endif
