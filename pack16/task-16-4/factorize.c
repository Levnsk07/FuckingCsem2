typedef struct Factors {
    int k; // сколько различных простых в разложении
    int primes[32]; // различные простые в порядке возрастания
    int powers[32]; // в какие степени надо эти простые возводить
} Factors;

void Factorize(int X, Factors *res) {
    res->k = 0;
    if (X == 1) {
        return;
    }
    short flag = 0;
    int current_prime = 2;
    while (X > 1) {
        if (X % current_prime == 0) {
            flag = 1;
            res->primes[res->k] = current_prime;
            res->powers[res->k] = 0;
            while (X % current_prime == 0) {
                res->powers[res->k]++;
                X /= current_prime;
            }
            res->k++;
        }
        // current_prime++;

        if (current_prime == 2) {
            current_prime++;
        } else {
            current_prime += 2;
        }

        //
        // if (flag == 1) {
        //     current_prime += current_prime / 2;
        //     flag = 0;
        // } else {
        //     current_prime++;
        // }
    }
}
