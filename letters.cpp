#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int TEXT_HEIGHT = 5; //The height of each block letter (minus spaces).
const int TEXT_WIDTH = 5; //The width of each block letter (minus spaces).
const int LINE_SIZE = 80/(TEXT_WIDTH + 1); //The maximum allowed length of a line before it has to split it up.
const string LETTERS[30][TEXT_HEIGHT] = //Source for what to turn input characters into, with reversed x and y:
{
    { "  A  ", " A A ", "AAAAA", "A   A", "A   A" },
    { "BBBB ", "B   B", "BBBB ", "B   B", "BBBB " },
    { " CCC ", "C   C", "C    ", "C   C", " CCC " },
    { "DDDD ", "D   D", "D   D", "D   D", "DDDD " },
    { "EEEEE", "E    ", "EEE  ", "E    ", "EEEEE" },
    { "FFFFF", "F    ", "FFF  ", "F    ", "F    " },
    { " GGGG", "G    ", "G GGG", "G   G", " GGG " },
    { "H   H", "H   H", "HHHHH", "H   H", "H   H" },
    { "IIIII", "  I  ", "  I  ", "  I  ", "IIIII" },
    { "JJJJJ", "  J  ", "  J  ", "  J  ", "JJ   " },
    { "K   K", "K  K ", "KKK  ", "K  K ", "K   K" },
    { "L    ", "L    ", "L    ", "L    ", "LLLLL" },
    { "M   M", "MM MM", "M M M", "M   M", "M   M" },
    { "N   N", "NN  N", "N N N", "N  NN", "N   N" },
    { " OOO ", "O   O", "O   O", "O   O", " OOO " },
    { "PPPP ", "P   P", "PPPP ", "P    ", "P    " },
    { " QQQ ", "Q   Q", "Q Q Q", "Q  QQ", " QQQQ" },
    { "RRRR ", "R   R", "RRRR ", "R   R", "R   R" },
    { " SSSS", "S    ", " SSS ", "    S", "SSSS " },
    { "TTTTT", "  T  ", "  T  ", "  T  ", "  T  " },
    { "U   U", "U   U", "U   U", "U   U", " UUU " },
    { "V   V", "V   V", "V   V", " V V ", "  V  " },
    { "W   W", "W   W", "W W W", "W W W", " W W " },
    { "X   X", " X X ", "  X  ", " X X ", "X   X" },
    { "Y   Y", " Y Y ", "  Y  ", "  Y  ", "  Y  " },
    { "ZZZZZ", "   Z ", "  Z  ", " Z   ", "ZZZZZ" },
    { "     ", "     ", "     ", "     ", "     " },
    { "     ", "     ", "     ", " ..  ", " ..  " },
    { " !!  ", " !!  ", " !!  ", "     ", " !!  " },
    { "???? ", "   ??", " ??  ", "     ", " ??  " }
};

int main()
{
    cout << "Welcome to the new Textifier 5x5!\nWhen you are done, type \"quit\", to exit.\nNow, Speak!\n\n";
    string user_input; //User's typed-in phrase.
    string input_transformed[TEXT_HEIGHT]; //A virtical array of strings of symbols that the user's input will be transformed into.

    getline(cin, user_input);
    while (user_input != "quit")
    {
        cout << endl;
        int input_length = user_input.length(); //Number of characters in the user's input.
        int number_of_lines = input_length/LINE_SIZE; //Number of Lines the block letters will need to be broken into.
        int remainder_size = input_length%LINE_SIZE; //Size of the last line of block letters.
        if (remainder_size != 0)
        {
            number_of_lines ++;
        }
        for (int h = 0; h < number_of_lines; h++) //h is which line of block letters we are on.
        {
            int current_line_size = LINE_SIZE;
            if (h == number_of_lines)
            {
                current_line_size = remainder_size;
            }
            for (int i = 0; i < TEXT_HEIGHT; i++) //i is which strip of the current line of block letters we are on.
            {
                input_transformed[i] = " ";
                for (int j = 0; j < current_line_size; j++) //j is which block letter in the current line of block letters we are on.
                {
                    int input_ascii = (int) user_input[(h * LINE_SIZE) + j]; //The ASCII code for the letter being turned into a block letter.
                    int output_ascii = 26; //My own code number for the block letter being produced.
                    string input_toadd; //The strip of symbols that make up a row in the block letter I'm working on.
                    if ((input_ascii >= 65) && (input_ascii <= 90))
                    {
                        output_ascii = input_ascii - 65;
                    }
                    if ((input_ascii >= 97) && (input_ascii <= 122))
                    {
                        output_ascii = input_ascii - 97;
                    }
                    if (input_ascii == 46)
                    {
                        output_ascii = 27;
                    }
                    if (input_ascii == 33)
                    {
                        output_ascii = 28;
                    }
                    if (input_ascii == 63)
                    {
                        output_ascii = 29;
                    }
                    input_toadd = LETTERS[output_ascii][i];
                    for (int k = 0; k < TEXT_WIDTH; k++) //k is which symbol in the current strip of the current block letter we are on.
                    {                                    //This block of code will randomize the symbols making up the block letter.
                        int current_ascii = (int) input_toadd[k]; //The singular symbol in the strip I'm currently working on.
                        if (current_ascii != 32)
                        {
                            current_ascii = (rand() % 93) + 33;
                            input_toadd[k] = (char) current_ascii;
                        }
                    }
                    input_transformed[i] += (input_toadd + " ");
                }
                input_transformed[i] += "\n";
                cout << input_transformed[i];
            }
            cout << "\n";
        }
        getline(cin, user_input);
    }
    return(0);
}
