#pragma once

class DisplayInterface {
public:
	virtual ~DisplayInterface() {}

	virtual bool needs_update() = 0;
	virtual void render() = 0;
};
