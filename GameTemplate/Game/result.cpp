#include "stdafx.h"
#include "result.h"
#include "score.h"

result::result()
{
}

result::~result()
{
}

bool result::Start()
{
	NewGO< score>(0);
	return true;
}

void result::Update()
{
}
