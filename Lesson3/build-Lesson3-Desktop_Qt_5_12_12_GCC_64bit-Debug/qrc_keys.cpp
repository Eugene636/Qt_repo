/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.12.12
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // /home/hugo/Documents/Qt_exp/Lesson1_home_task/Lesson3/Lesson3/keys/keys.txt
  0x0,0x0,0x0,0x40,
  0x30,
  0x78,0x34,0x65,0x20,0x30,0x78,0x30,0x34,0x30,0x30,0x30,0x30,0x30,0x30,0xa,0x30,
  0x78,0x35,0x33,0x20,0x30,0x78,0x30,0x34,0x30,0x30,0x30,0x30,0x30,0x30,0xa,0x30,
  0x78,0x34,0x66,0x20,0x30,0x78,0x30,0x34,0x30,0x30,0x30,0x30,0x30,0x30,0xa,0x30,
  0x78,0x35,0x31,0x20,0x30,0x78,0x30,0x34,0x30,0x30,0x30,0x30,0x30,0x30,0xa,
  
};

static const unsigned char qt_resource_name[] = {
  // keys
  0x0,0x4,
  0x0,0x7,0x1d,0x3,
  0x0,0x6b,
  0x0,0x65,0x0,0x79,0x0,0x73,
    // keys.txt
  0x0,0x8,
  0xd,0x6,0x55,0xd4,
  0x0,0x6b,
  0x0,0x65,0x0,0x79,0x0,0x73,0x0,0x2e,0x0,0x74,0x0,0x78,0x0,0x74,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/keys
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/keys/keys.txt
  0x0,0x0,0x0,0xe,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x82,0x9c,0x5b,0xc5,0x57,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_keys)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_keys)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_keys)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_keys)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_keys)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_keys)(); }
   } dummy;
}
