#include <iostream>
#include <aws/core/Aws.h>
#include <aws/core/utils/Outcome.h>
#include <aws/core/utils/logging/ConsoleLogSystem.h>
#include <aws/core/utils/logging/AWSLogging.h>

#include <aws/rds/RDSClient.h>
#include <aws/rds/RDSEndpoint.h>
#include <aws/rds/RDSRequest.h>

#include <aws/core/client/ClientConfiguration.h>

#include "aws_io.h"
#include "aws_accesskey.h"

AWS_IO::AWS_IO()
{
	//AWS_RDS

	Aws::SDKOptions options;
	Aws::InitAPI(options);
	{
		Aws::Client::ClientConfiguration clientCFG;
		Aws::RDS::RDSClient rdsClient(clientCFG);

	}
	Aws::ShutdownAPI(options);
}
