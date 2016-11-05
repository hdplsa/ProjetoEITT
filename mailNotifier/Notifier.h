#ifndef NOTIFIER_H_INCLUDED
#define NOTIFIER_H_INCLUDED


enum NotificationType {PiscaLED, GSM};

class Notifier{
  NotificationType type;

public:
  Notifier(NotificationType type);
  ~Notifier();
};

#endif
