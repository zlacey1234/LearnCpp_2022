int ReadNumber();
void WriteAnswer(int answer_value);

int main() {
    int user_input_1{ ReadNumber() };
    int user_input_2{ ReadNumber() };

    WriteAnswer( user_input_1 + user_input_2);

    return 0;
}