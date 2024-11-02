#pragma once
#include "TextGo.h"
class UiMessage :
    public TextGo
{
protected:

public:
	UiMessage(const std::string& fontId, const std::string& name = "");
	virtual ~UiMessage() = default;

	void Init() override;

	void Reset() override;
};

