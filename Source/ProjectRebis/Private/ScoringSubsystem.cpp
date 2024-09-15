// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoringSubsystem.h"

UScoringSubsystem::UScoringSubsystem()
{
	ResetCurrentScore();
}

int32 UScoringSubsystem::WriteTotalScore(double TimeElapsed)
{
	int32 BufferTimeScore = BaseScoreValues.TIME_1;
	if (TimeElapsed < 20.0f) 
	{
		BufferTimeScore = BaseScoreValues.TIME_4;
	}
	else if (TimeElapsed < 30.0f) 
	{
		BufferTimeScore = BaseScoreValues.TIME_3;
	}
	else if (TimeElapsed < 40.0f) 
	{
		BufferTimeScore = BaseScoreValues.TIME_2;
	}
	else if (TimeElapsed < 60.0f) 
	{
		BufferTimeScore = BaseScoreValues.TIME_1;
	}
	TotalScore = CurrentScore + BufferTimeScore;
	return TotalScore;
}

void UScoringSubsystem::UpdateCurrentScore(double Multiplier)
{
	CurrentScore = CurrentScore + Multiplier * BaseScoreValues.ENEMY;
}

void UScoringSubsystem::SubtractCurrentScore()
{
	CurrentScore = CurrentScore - BaseScoreValues.HIT_PENALTY;
}

void UScoringSubsystem::ResetCurrentScore()
{
	CurrentScore = 0;
	TotalScore = 0;
}
