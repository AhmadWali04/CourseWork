SELECT TABLE_NAME, COLUMN_NAME, REFERENCED_TABLE_NAME, REFERENCED_COLUMN_NAME
FROM information_schema.KEY_COLUMN_USAGE
WHERE TABLE_SCHEMA = 'dcris' OR CONSTRAINT_SCHEMA = 'dcris' AND CONSTRAINT_NAME = 'PRIMARY'
ORDER BY TABLE_NAME,COLUMN_NAME
