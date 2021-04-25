#include <aws/core/Aws.h>
#include <aws/iam/IAMClient.h>
#include <aws/iam/model/CreateAccessKeyRequest.h>
#include <aws/iam/model/CreateAccessKeyResult.h>
#include <aws/iam/model/ListAccessKeysRequest.h>
#include <aws/iam/model/ListAccessKeysResult.h>

#include <iomanip>
#include <iostream>

#include "aws_accesskey.h"

AWS_ACCESSKEY::AWS_ACCESSKEY()
{

}

AWS_ACCESSKEY::~AWS_ACCESSKEY()
{
}

void AWS_ACCESSKEY::createRequestKey()
{
	Aws::IAM::IAMClient iam;

	Aws::IAM::Model::CreateAccessKeyRequest request;
	Aws::String user_name = "dev_hklee";
	request.SetUserName(user_name);

	auto outcome = iam.CreateAccessKey(request);
	if (!outcome.IsSuccess())
	{
		std::cout << "Error creating access key for IAM user " << user_name
			<< ":" << outcome.GetError().GetMessage() << std::endl;
	}
	else
	{
		const auto &accessKey = outcome.GetResult().GetAccessKey();
		std::cout << "Successfully created access key for IAM user " <<
			user_name << std::endl << "  aws_access_key_id = " <<
			accessKey.GetAccessKeyId() << std::endl <<
			" aws_secret_access_key = " << accessKey.GetSecretAccessKey() <<
			std::endl;
	}
}

void AWS_ACCESSKEY::getListAccessKeys()
{
	Aws::IAM::IAMClient iam;
	Aws::IAM::Model::ListAccessKeysRequest request;
	Aws::String user_name = "dev_hklee";
	request.SetUserName(user_name);

	bool done = false;
	bool header = false;
	while (!done)
	{
		auto outcome = iam.ListAccessKeys(request);
		if (!outcome.IsSuccess())
		{
			std::cout << "Failed to list access keys for user " << user_name
				<< ": " << outcome.GetError().GetMessage() << std::endl;
			break;
		}

		if (!header)
		{
			std::cout << std::left << std::setw(32) << "UserName" <<
				std::setw(30) << "KeyID" << std::setw(20) << "Status" <<
				std::setw(20) << "CreateDate" << std::endl;
			header = true;
		}

		const auto &keys = outcome.GetResult().GetAccessKeyMetadata();
		for (const auto &key : keys)
		{
			Aws::String statusString =
				Aws::IAM::Model::StatusTypeMapper::GetNameForStatusType(
					key.GetStatus());
			std::cout << std::left << std::setw(32) << key.GetUserName() <<
				std::setw(30) << key.GetAccessKeyId() << std::setw(20) <<
				statusString << std::setw(20) <<
				key.GetCreateDate().ToGmtString("2021-04-18") << std::endl;
		}

		if (outcome.GetResult().GetIsTruncated())
		{
			request.SetMarker(outcome.GetResult().GetMarker());
		}
		else
		{
			done = true;
		}
	}
}
