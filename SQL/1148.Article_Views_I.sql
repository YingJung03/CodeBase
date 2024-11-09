# Write your MySQL query statement below
SELECT distinct author_id AS id
FROM Views
WHERE author_id=viewer_id
ORDER BY id ASC;

# Write your MySQL query statement below
# 較有效率
-- SELECT distinct author_id AS id
-- FROM Views
-- WHERE author_id=viewer_id
-- ORDER BY 1;