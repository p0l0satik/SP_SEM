
int main()
{
    int count;
    std::cin >> count;
    Holder *io = new Holder[count];
    for (int t = 0; t < count / 2; t++) {
        io[t].swap(io[count - t - 1]);
    }
    delete[] io;
}