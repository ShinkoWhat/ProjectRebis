// Fill out your copyright notice in the Description page of Project Settings.


#include "TelemetrySubsystem.h"

#include "HLSLTree/HLSLTreeEmit.h"

UTelemetrySubsystem::UTelemetrySubsystem()
{
	URL = "https://elastic.es.hronrad.eternalfusion.ru/";
	IndicesName = "test_telemetry_1";
}

void UTelemetrySubsystem::ReadIndices()
{
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	Request->SetVerb("GET");
	Request->SetURL(URL + IndicesName + "/_search");
	Request->SetHeader(TEXT("Authorization"), TEXT("Basic YmFzZV91c2VyOk5mNFFNRjVmWFM0SnZpR3Nhd3Vj"));

	Request->ProcessRequest();
}

void UTelemetrySubsystem::WriteIndices(FAttemptData AttemptData)
{
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	Request->SetVerb("POST");
	Request->SetURL(URL + IndicesName + "/_doc");
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("Authorization"), TEXT("Basic YmFzZV91c2VyOk5mNFFNRjVmWFM0SnZpR3Nhd3Vj"));
	
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());

	JsonObject->SetStringField(TEXT("PlayerName"), AttemptData.PlayerName);
	JsonObject->SetStringField(TEXT("PlayerDiagnosis"), AttemptData.PlayerDiagnosis);
	JsonObject->SetStringField(TEXT("LevelName"), AttemptData.LevelName.ToString());
	JsonObject->SetNumberField(TEXT("AttemptNumber"), AttemptData.AttemptNumber);
	JsonObject->SetNumberField(TEXT("TimeElapsed"), int(AttemptData.TimeElapsed * 1000));
	JsonObject->SetNumberField(TEXT("EnemiesDefeated"), AttemptData.EnemiesDefeated);
	JsonObject->SetNumberField(TEXT("HitsTaken"), AttemptData.HitsTaken);
	JsonObject->SetNumberField(TEXT("TotalScore"), AttemptData.TotalScore);
	
	FString OutputString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);
	Request->SetContentAsString(OutputString);

	Request->OnProcessRequestComplete().BindLambda([](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
	{
		if (bWasSuccessful && Response.IsValid())
		{
			FString ResponseStr = Response->GetContentAsString();
			UE_LOG(LogTemp, Warning, TEXT("%s"), *ResponseStr);
		}
	});
	
	Request->ProcessRequest();
}
