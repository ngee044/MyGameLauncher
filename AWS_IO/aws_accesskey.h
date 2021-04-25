#pragma once
class AWS_ACCESSKEY
{
public:
	AWS_ACCESSKEY();
	~AWS_ACCESSKEY();

	// 계정 생성 (사용하면 안됨)
	void createRequestKey();
	//지정된 사용자의 액세스 키를 나열
	void getListAccessKeys();
};

