#ifndef KEYS_H
#define KEYS_H
#include <Qt>

struct KeyShortcut {
  Qt::Key key_code;
  Qt::KeyboardModifier key_modifier;
  bool operator==(const KeyShortcut &) const;
  void operator=(const KeyShortcut &);
  KeyShortcut();
};
class Keys {
  KeyShortcut code_key_save_;
  KeyShortcut code_key_open_;
  KeyShortcut code_key_create_;
  KeyShortcut code_key_exit_;

public:
  void writeKeysToFile();
  const KeyShortcut &getCodeKeySave() const;
  const KeyShortcut &getCodeKeyOpen() const;
  const KeyShortcut &getCodeKeyCreate() const;
  const KeyShortcut &getCodeKeyExit() const;
  bool setCodeKeySave(const KeyShortcut &);
  bool setCodeKeyOpen(const KeyShortcut &);
  bool setCodeKeyCreate(const KeyShortcut &);
  bool setCodeKeyExit(const KeyShortcut &);
  Keys();
};

#endif // KEYS_H
