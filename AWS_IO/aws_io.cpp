#include <aws/core/Aws.h>
#include <aws/core/utils/Outcome.h>
#include <aws/core/utils/logging/ConsoleLogSystem.h>
#include <aws/core/utils/logging/AWSLogging.h>

#include <aws/dynamodb/DynamoDBClient.h>
#include <aws/dynamodb/model/AttributeDefinition.h>
#include <aws/dynamodb/model/GetItemRequest.h>
#include <aws/core/client/ClientConfiguration.h>

#include "aws_io.h"

AWS_IO::AWS_IO()
{
	Aws::SDKOptions options;
	Aws::InitAPI(options);
	{
		const Aws::String table = "MyLauncher";
		const Aws::String id = "ngee044";

		Aws::Client::ClientConfiguration clientCFG;
		Aws::DynamoDB::DynamoDBClient dynamoClient(clientCFG);

		Aws::DynamoDB::Model::GetItemRequest req;
		req.SetTableName(table);
		Aws::DynamoDB::Model::AttributeValue hashKey;
		hashKey.SetS(id);
		req.AddKey("id", hashKey);

		const Aws::DynamoDB::Model::GetItemOutcome& result = dynamoClient.GetItem(req);
		if (result.IsSuccess())
		{
			const Aws::Map<Aws::String, Aws::DynamoDB::Model::AttributeValue>& item = result.GetResult().GetItem();
			if (item.size() > 0)
			{
				for (const auto& i : item)
					std::cout << i.first << ": " << i.second.GetS() << std::endl;

			}
			else
			{
				std::cout << "No item found with the key" << id << std::endl;
			}
		}
		else
		{
			std::cout << "Failed to get itme: " << result.GetError().GetMessage();
		}

	}
	Aws::ShutdownAPI(options);
}
