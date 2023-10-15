// select
// monitor.iban as sender,
// count(transactions.sender) AS transactions,
// group_concat(currencies.name ORDER BY currencies.name) as currencies
// FROM
// (
//     monitor
//     INNER JOIN transactions ON monitor.iban = transactions.sender
// )
// INNER JOIN currencies ON transactions.currency_code = currencies.code
// WHERE
// transactions.completed = "yes"
// GROUP BY
// monitor.iban
// ORDER BY
// monitor.iban;

// select client, group_concat(traffic.protocol order by(traffic.traffic_in + traffic.traffic_out) desc) as protocol
// from traffic
// group by client
// order by client;

// CREATE TABLE participants(
//     participant_id INT PRIMARY KEY,
//     participant_name VARCHAR(255),
//     slice_count INT,
//     bet DECIMAL(10, 2)
// );

// --Inserting sample data into the participants table
// INSERT INTO participants(participant_id, participant_name, slice_count, bet) VALUES
// (1, 'Alice', 5, 100.00),
// (2, 'Bob', 8, 150.00),
// (3, 'Charlie', 5, 120.00),
// (4, 'David', 6, 130.00),
// (5, 'Eve', 5, 110.00),
// (6, 'Frank', 7, 140.00),
// (7, 'Grace', 8, 160.00),
// (8, 'Hank', 6, 125.00),
// (9, 'Ivy', 7, 135.00);


// SELECT
// participant_name AS winner,
// (bet) AS total_cash
// FROM(
//     SELECT
//     p1.participant_id,
//     p1.participant_name,
//     p1.bet
//     FROM participants p1
//     WHERE p1.slice_count = (
//         SELECT MAX(slice_count)
//         FROM participants p2
//         WHERE p2.slice_count = p1.slice_count
//     )
// ) AS winner
// ORDER BY participant_name;
