SELECT 
    b.broadDesc
FROM 
    broad b
WHERE 
    b.broadId NOT IN (
        SELECT 
            n.narrowBroadId
        FROM 
            narrow n
    )
ORDER BY 
    b.broadDesc;
