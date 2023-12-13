#include "user.h"
#include "message.h"

QDataStream& operator<<( QDataStream& D, const User& U ) {
    D << U.getId() << U.getLogin() << U.getPassword();
    return D;
}

QDataStream& operator>>( QDataStream& D, User& U ) {
    D >> U.id >> U.login >> U.password;
    return D;
}

QDataStream& operator<<( QDataStream& D, const Message& M ) {
    D << M.getTime() << M.getName() << M.getMessage();
    return D;
}

QDataStream& operator>>( QDataStream& D, Message& M ) {
    D >> M.time >> M.name >> M.message;
    return D;
}


//QDebug operator<<( QDebug D, const User& U ) {
//    D << QString( "user( %1, %2 )" ).arg( U.getLogin() ).arg( U.getId() );
//    return D;
//}
