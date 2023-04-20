int fatorial(int number)
{
    return number <= 1 ? 1 : number * fatorial(number - 1);
}

float sum(float x, float z)
{
    return x + z;
}

float subtract(float x, float z)
{
    return x - z;
}

float multiplier(float x, float z)
{
    return x * z;
}

float division(float x, float z)
{
    return x / z;
}

float percent(int x, int z)
{
    return division(multiplier(x, z), 100);
}

int fibonacci(int number)
{

    if (number == 0)
        return 0;

    if (number < 3)
        return 1;

    return fibonacci(number - 1) + fibonacci(number - 2);
}

float pow(int x, int z)
{

    if (z == 0)
        return 1;

    return (float)multiplier(x, pow(x, z - 1));
}

int combination(int x, int z)
{
    return division(fatorial(x), fatorial(z) * (fatorial(x - z)));
}

float average(float *vetor, int tam)
{

    float sum = 0;

    for (int i = 0; i < tam; i++)
        sum += vetor[i];

    return sum / tam;
}

float mode(float *vetor, int tam)
{

    int sum = 0;
    float count[tam], mode = 0;

    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {

            if (vetor[i] == vetor[j])
            {
                count[i]++;

                if (count[i] > sum)
                {
                    sum = count[i];
                    mode = vetor[i];
                }
            }
        }
        count[i] = 0;
    }

    return mode;
}

float mediana(float *vetor, int tam)
{

    ascList(vetor, tam);

    if (tam % 2 == 0)
    {
        float x = vetor[tam / 2], z = vetor[(tam / 2) - 1];
        return (x + z) / 2;
    }

    return vetor[(tam - 1) / 2];
}

void descList(float *vetor, int tam)
{

    int aux = 0;

    for (int i = 0; i < tam; i++)
    {
        for (int j = (i + 1); j < tam; j++)
        {

            if (vetor[i] < vetor[j])
            {
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
        }
    }
}

void ascList(float *vetor, int tam)
{

    int aux = 0;

    for (int i = 0; i < tam; i++)
    {
        for (int j = (i + 1); j < tam; j++)
        {

            if (vetor[i] > vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}