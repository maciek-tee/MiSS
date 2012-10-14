#include <gmpxx.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

//#define DEBUG

using namespace std;

unsigned int count_sequence_period(vector<mpz_class> sequence);

void debug_msg(int msg);

void debug_msg(mpz_class msg);

void debug_msg(string msg);

void print_mpz_with_precision(mpz_class number, int precision);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    unsigned long d = atol(argv[1]);

    debug_msg(d);

    vector<mpz_class> numbers;

    mpz_class number;
    mpz_class sum;
    mpz_class sum_of_squares;
    while(cin >> number)
    {
        sum += number;
        mpz_class number_squared = number * number;
        sum_of_squares += number_squared;
        numbers.push_back(number);
    }

    debug_msg("sum:");
    debug_msg(sum);

    debug_msg("sum_of_squares:");
    debug_msg(sum_of_squares);

    mpz_class precision;
    mpz_class base = 10;

    mpz_class n = numbers.size();
    mpz_class n_square = n * n;

    mpz_pow_ui(precision.get_mpz_t(),base.get_mpz_t(),d);

    debug_msg("precision:");

    debug_msg("LICZENIE RESULTA");
    mpz_class result = (sum*precision)/n;
    debug_msg("PO LICZENIE RESULTA");
    print_mpz_with_precision(result, d);
    debug_msg("PO WYPISANIU RESULTA");

    //mpz_class result_squares = (sum_of_squares*precision)/(mpz_class)numbers.size();
    //mpz_class variation = ((((mpz_class)numbers.size())*(sum_of_squares*precision)) - (result*result)) / (precision*precision);

    mpz_class variation = ((n * sum_of_squares - sum * sum) * precision ) / n_square;

    print_mpz_with_precision(variation, d);

    cout << 12 << endl;

/*mpz_class n,q;
        gmp_randclass generator(gmp_randinit_default);
        generator.seed(time(NULL));
        if(argc > 1)
                n = argv[1];
        else
                n = generator.get_z_bits(25) + 1;
        cerr<<"Generuje "<<n<<" liczb"<<endl;
        for(n=n; n>0; n--)
        {
                q = generator.get_z_bits(1);
                if(q == 0)
                        cout<<generator.get_z_bits(65)<<' ';
                else
                        cout<<'-'<<generator.get_z_bits(65)<<' ';
        }
        cout<<endl;
        cerr<<"Wygenerowano"<<endl;*/

    return 0;
}

unsigned int count_sequence_period(vector<int> sequence)
{
    int sequence_length = (int) sequence.size();
    int possible_period = 0;
    bool is_sequence_broken = false;

    for (int i = 1; i < sequence_length; i++)
    {
        if (sequence[0] == sequence[i])
        {   
            possible_period = i;
            is_sequence_broken = false;

            for (int j = 0; j < possible_period; j++)
            {
                for (int k = possible_period + j; k < sequence_length; k += possible_period)
                {
                    if (sequence[j] != sequence[k])
                    {
                        is_sequence_broken = true;
                        break;
                    }
                }

                if (is_sequence_broken)
                {
                    break;
                }
            }
        }

        if (!is_sequence_broken && (possible_period != 0))
        {
            return possible_period;
        }
    }

    return 1;
}

void debug_msg(int msg)
{
    #ifdef DEBUG
    cout<<msg<<endl;
    #endif
}

void debug_msg(mpz_class msg)
{
    #ifdef DEBUG
    cout<<msg<<endl;
    #endif
}

void debug_msg(string msg)
{
    #ifdef DEBUG
    cout<<msg<<endl;
    #endif
}

void print_mpz_with_precision(mpz_class number, int precision)
{
    if(number==0)
    {
        cout<<"0"<<endl;
        return;
    }

    string temp_result = number.get_str();

    int a = 0;
    bool zero = true;
    int zero_to_remove = 0;
    for(int i=temp_result.length()-1; i>=0; i--)
    {
        if(temp_result[i]!='0')
            {
                zero = false;
            }

        if(zero)
        {
            zero_to_remove++;
        }

        a++;
        if(a==precision)
        {
            temp_result.insert(i,".");
            break;
        }
    }

    if(zero_to_remove>0)
    {
        temp_result.erase(temp_result.length()-zero_to_remove,zero_to_remove);
    }

    /*string temp = "";

    /if(number==0)
    {
        temp = "0";
    }
    else
    {
        int a = 0;
        bool zero = true;
        for(int i=temp_result.length()-1; i>=0; i--)
        {
            if(temp_result[i]!='0')
            {
                zero = false;
            }

            a++;

            if(a<=precision && zero && temp_result[i]=='0')
            {

            }
            else
            {
                temp = temp_result[i] + temp;

                if(a==precision)
                {
                    temp = "." + temp;
                }
            }
        }
    }*/

    debug_msg("result with prec:");
    cout<<temp_result<<endl;
}





























