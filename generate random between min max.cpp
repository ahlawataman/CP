int main() {
    int min = 5;
    int max = 25;
    srand(time(NULL)); // SEED VALUE
    int range = max - min + 1;
    int num = rand() % range + min;
    cout<<num;
}
