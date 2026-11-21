#include "Entidade.h"

Entidade::Entidade() : x(0), y(0)
{
}

Entidade::~Entidade()
{
}

void Entidade::setPoint(float px, float py)
{
    x = static_cast<int>(px);
    y = static_cast<int>(py);
}
