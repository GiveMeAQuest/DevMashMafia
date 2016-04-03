УСЛОВНЫЕ ОБОЗНАЧЕНИЯ
{a, b, c, ...} - JSON-объект с полями "a", "b", "c", ...
[a] - массив JSON-объектов "а"
Все названия полей, а также строковые значения надо заключать в двойные кавычки!

Чтобы зайти в комнату:
- event: "join room"
- data: {nickname, room_id}
 - nickname: ник игрока (строка)
 - room_id: ID комнаты (число)

Что возвращается:
- event: "room joined"
- data: room_id
 - room_id: ID комнаты, в которую зашёл игрок (число)
 

Чтобы создать комнату:
- event: "create room"
- data: {players}
 - players: Необходимое кол-во игроков в комнате (число)
 
Что возвращается:
- event: "room created"
- data: room_id
 - room_id: ID созданной комнаты (число)
 

Чтобы получить список игроков в комнате (до начала игры):
- event: "get waiting players"
- data: -

Что возвращается:
- event: "players"
- data: [player]
 - player: {id, nickname}
  - id: ID игрока (число)
  - nickname: Ник игрока (строка)
  

Чтобы выйти из комнаты:
- event: "leave room"
- data: -

Что возвращается:
- event: "room left"
- data: -


Что приходит само по себе:

Когда игрок находится в комнате (до начала игры):
