#pragma once
class AWS_ACCESSKEY
{
public:
	AWS_ACCESSKEY();
	~AWS_ACCESSKEY();

	// ���� ���� (����ϸ� �ȵ�)
	void createRequestKey();
	//������ ������� �׼��� Ű�� ����
	void getListAccessKeys();
};

