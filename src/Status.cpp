#include "Status.h"
#include "WebPage.h"
#include <sstream>

Status::Status(WebPage *page, QObject *parent) : Command(page, parent) {
}

void Status::start(QStringList &arguments) {
  Q_UNUSED(arguments);
  std::stringstream sstr(std::stringstream::in | std::stringstream::out);
  sstr << page()->getLastStatus();
  emit finished(new Response(true, QString(sstr.str().c_str())));
}

