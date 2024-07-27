// Fill out your copyright notice in the Description page of Project Settings.


#include "myCPPBlueprintFunctionLibrary.h"
#include <math.h>

float UmyCPPBlueprintFunctionLibrary::myCPPSin(float rad)
{
	double Value = sin((double)rad);
	return (float)Value;
}