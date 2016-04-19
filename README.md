#API сокетов

#####События, отправляемые пользователем серверу
- [Вход в комнату](#join-room)
- [Создание комнаты](#create-room)
- [Получение списка игроков в комнате (до начала игры)](#get-waiting-players)
- [Выход из комнаты](#leave-room)
- [Получение данных о комнате, в которой находится игрок](#get-room)
- [Возобновление игровой сесии](#reconnect)
- [Начало игры](#start-game)

#####События, отправляемые сервером пользователю
- [Любая ошибка](#err)
- [В комнату игрока зашёл другой игрок](#player-joined)
- [Из комнаты игрока вышел другой игрок](#player-left)
- [Из комнаты игрока вышел хост и сервер назначил нового хоста](#host-changed)
- [Назначение игроку роли](#role)
- [Смена фазы игры в комнате игрока](#phase-changed)

#####Фазы игры
- [night begin](#night-begin)


##Условные обозначения
`{a, b, c, ...}` - JSON-объект с полями "a", "b", "c", ...

`[a]` - массив JSON-объектов "а"

Все названия полей, а также строковые значения надо заключать в двойные кавычки!

##События

###События, отправляемые пользователем серверу


<a name='join-room'></a>
####Вход в комнату
- `event`: "join room"
- `data`: {nickname, room\_id}
  - `nickname`: ник игрока (строка)
  - `room_id`: ID комнаты (число)

__Ответ сервера__
- `event`: "room joined"
- `data`: {id, nickname, room\_id, reconnect\_token}
  - `id`: Ваш ID как игрока (число)
  - `nickname`: Ваш ник (строка)
  - `room_id`: ID комнаты, в которую зашёл игрок (число)
  - `reconnect_token`: Ключ для возобновления игровой сессии

---

<a name='create-room'></a>
####Создание комнаты
- `event`: "create room"
- `data`: {players}
  - `players`: Необходимое кол-во игроков в комнате (число)
 
__Ответ сервера__
- `event`: "room created"
- `data`: {id}
  - `id`: ID созданной комнаты (число)
 
---

<a name='get-waiting-players'></a>
####Получение списка игроков в комнате (до начала игры)
- `event`: "get waiting players"
- `data`: -

__Ответ сервера__
- `event`: "players"
- `data`: {players}
  - `players`: [player]
    - `player`: {id, nickname}
      - `id`: ID игрока (ВСЕГДА число)
      - `nickname`: Ник игрока (строка)

---

<a name='leave-room'></a>
####Выход из комнаты
- `event`: "leave room"
- `data`: -

__Ответ сервера__
- `event`: "room left"
- `data`: -

---

<a name='get-room'></a>
####Получение данных о комнате, в которой находится игрок
- `event`: "get room"
- `data`: -
 
__Ответ сервера__
- `event`: "room"
- `data`: {id, host_id, phase}
  - `id`: ID комнаты (число)
  - `host_id`: ID хоста комнаты (число)
  - `phase`: Название текущей фазы комнаты (строка)

---

<a name='reconnect'></a>
####Возобновление игровой сесии
- `event`: "reconnect"
- `data`: {reconnect_token}
  - `reconnect_token`: Ключ для возобновления игровой сессии (строка)

__Ответ сервера__

См. [вход в комнату](#join-room)

---

<a name="start-game"></a>
####Начало игры
- `event`: "start game"
- `data`: -


###События, отправляемые сервером пользователю


<a name='err'></a>
####Любая ошибка
- `event`: "err"
- `data`: {event, error}
  - `event`: Название события, во время которого произошла ошибка (строка)
  - `error`: Текст ошибки (строка)
 
---

<a name='player-joined'></a>
####В комнату игрока зашёл другой игрок
- `event`: "player joined"
- `data`: {id, nickname, room_id}
  - `id`: ID зашедшего игрока (число)
  - `nickname`: Ник зашедшего игрока (строка)
  - `room_id`: ID комнаты, в которую зашёл игрок (число)

---

<a name='player-left'></a>
####Из комнаты игрока вышел другой игрок
- `event`: "player left"
- `data`: {id}
  - `id`: ID вышедшего игрока (число)

---

<a name='host-changed'></a>
####Из комнаты игрока вышел хост и сервер назначил нового хоста
- `event`: "host changed"
- `data`: {id}
  - `id`: ID игрока, ставшего хостом (число)

---

<a name='role'></a>
####Назначение игроку роли
- `event`: "role"
- `data`: {name}
  - `name`: Название роли (строка)

---

<a name='phase-changed'></a>
####Смена фазы игры в комнате игрока
- `event`: "phase changed"
- `data`: {phase_name}
  - `phase_name`: Название новой фазы (строка)

Подробнее см. [Фазы игры](#phases)

<a name='phases'></a>
### Фазы игры

<a name='night-begin'></a>
####night begin
- `data`: -
