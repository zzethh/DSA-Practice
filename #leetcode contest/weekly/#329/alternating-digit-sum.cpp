bool flag = true;
for (auto x : s) {
    if (x != '0') {
        flag = false;
    }
}
bool flag2 = true;
for (auto x : target) {
    if (x != '0') {
        flag2 = false;
    }
}
if (flag and flag2) return true;
if (flag) return false;
if (flag2) return false;
return true;