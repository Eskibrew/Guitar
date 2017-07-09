#ifndef AVATARLOADER_H
#define AVATARLOADER_H

#include "GitHubAPI.h"
#include <QIcon>
#include <QThread>
#include <QMutex>
#include <deque>
#include <QWaitCondition>
#include <set>
#include <string>

class WebContext;

class AvatarLoader : public QThread {
	Q_OBJECT
private:
	GitHubAPI github;

	struct RequestItem {
		std::string name;
		QIcon icon;
	};
	struct Private;
	Private *m;

protected:
	void run();
public:
	AvatarLoader();
	~AvatarLoader();
	QIcon fetch(const std::string &name, bool request);
	void interrupt();
	void start(WebContext *webcx);
signals:
	void updated();
};

#endif // AVATARLOADER_H